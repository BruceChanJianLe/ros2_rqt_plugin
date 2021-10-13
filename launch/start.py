from launch import LaunchDescription
from launch_ros.actions import Node


# Note that this is on Eloquent
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_rqt_plugin',
            node_executable='rqt_push_button',
            node_name='rqt_push_button'
        )
    ])