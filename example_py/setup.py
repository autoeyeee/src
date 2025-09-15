from setuptools import find_packages, setup

package_name = 'example_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lin',
    maintainer_email='lin@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    #tests_require=['pytest'],
    extras_require={
        'test': [
            'pytest>=6.0',
            'pytest-cov>=2.10',
            # 其他测试依赖...
        ]
    },
    entry_points={
        'console_scripts': [
            "node_02 = example_py.node_02:main"
        ],
    },

)


