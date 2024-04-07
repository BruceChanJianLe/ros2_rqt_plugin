# ROS2 RQT PLUGIN

This repository demonstrate rqt plugin on ROS2.

The steps of creating ROS2 version of plugin is quite similar to ROS1, for steps please refer to ROS1 version [here](https://github.com/BruceChanJianLe/ros-rqt-plugin).

If you are not familiar with qt, you may check out how to manually connect the signals and slots for your ui in the `manual_connect` branch.

This example uses the auto-connect [feature](https://doc.qt.io/qt-5/designer-using-a-ui-file.html#widgets-and-dialogs-with-auto-connect) to connect the slot and signal.
However, the downside is that you will need to pass your `node_` manually to your custom widget.
