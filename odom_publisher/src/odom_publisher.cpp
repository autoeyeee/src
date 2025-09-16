#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2/LinearMath/Quaternion.h>

class OdomPublisher : public rclcpp::Node
{
public:
    OdomPublisher(std::string name) : Node(name)
    {
        // 创建发布者，发布"odom"话题
        odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>(
            "odom", rclcpp::SensorDataQoS());
        
        // 创建定时器，定时发布odom消息
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(50),  // 20Hz频率发布
            std::bind(&OdomPublisher::publish_odom, this));
        
        RCLCPP_INFO(this->get_logger(), "Odom publisher node has been initialized.");
        
        // 初始化位置和姿态
        x_ = 0.0;
        y_ = 0.0;
        theta_ = 0.0;
    }

private:
    void publish_odom()
    {
        // 创建odom消息
        nav_msgs::msg::Odometry odom_msg;
        
        // 设置消息头部信息
        odom_msg.header.stamp = this->now();
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_footprint";
        
        // // 更新位置信息（这里模拟一个简单的移动路径）
        // x_ += 0.01;  // x方向每步增加0.01米
        // y_ = 0.5 * sin(x_);  // y方向做正弦运动
        // theta_ += 0.005;  // 缓慢旋转
        
        // 设置位置
        odom_msg.pose.pose.position.x = x_;
        odom_msg.pose.pose.position.y = y_;
        odom_msg.pose.pose.position.z = 0.0;
        
        // 设置姿态（将欧拉角转换为四元数）
        tf2::Quaternion quat;
        quat.setRPY(0.0, 0.0, theta_);  // 滚转、俯仰、偏航
        odom_msg.pose.pose.orientation.x = quat.x();
        odom_msg.pose.pose.orientation.y = quat.y();
        odom_msg.pose.pose.orientation.z = quat.z();
        odom_msg.pose.pose.orientation.w = quat.w();
        
        // 设置位置和姿态的协方差（模拟值）
        odom_msg.pose.covariance = {
            0.01, 0, 0, 0, 0, 0,
            0, 0.01, 0, 0, 0, 0,
            0, 0, 0.01, 0, 0, 0,
            0, 0, 0, 0.01, 0, 0,
            0, 0, 0, 0, 0.01, 0,
            0, 0, 0, 0, 0, 0.01
        };
        
        // 设置线速度和角速度（模拟值）
        odom_msg.twist.twist.linear.x = 0.1;
        odom_msg.twist.twist.linear.y = 0.0;
        odom_msg.twist.twist.linear.z = 0.0;
        odom_msg.twist.twist.angular.x = 0.0;
        odom_msg.twist.twist.angular.y = 0.0;
        odom_msg.twist.twist.angular.z = 0.05;
        
        // 设置速度的协方差（模拟值）
        odom_msg.twist.covariance = {
            0.01, 0, 0, 0, 0, 0,
            0, 0.01, 0, 0, 0, 0,
            0, 0, 0.01, 0, 0, 0,
            0, 0, 0, 0.01, 0, 0,
            0, 0, 0, 0, 0.01, 0,
            0, 0, 0, 0, 0, 0.01
        };
        
        // 发布消息
        odom_publisher_->publish(odom_msg);
        
        // 打印发布的信息
        RCLCPP_INFO_THROTTLE(this->get_logger(), 
                            *this->get_clock(), 1000,  // 每秒打印一次
                            "Publishing odom: x=%.2f, y=%.2f, theta=%.2f",
                            x_, y_, theta_);
    }
    
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    // 位置和姿态变量
    double x_, y_, theta_;
};

int main(int argc, char **argv)
{
    // 初始化ROS节点
    rclcpp::init(argc, argv);
    
    // 创建OdomPublisher节点
    auto node = std::make_shared<OdomPublisher>("odom_publisher");
    
    // 运行节点
    rclcpp::spin(node);
    
    // 关闭节点
    rclcpp::shutdown();
    return 0;
}
    