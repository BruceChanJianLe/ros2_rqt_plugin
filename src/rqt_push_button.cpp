#include "ros2_rqt_plugin/rqt_push_button.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QStringList>

PLUGINLIB_EXPORT_CLASS(rqt_plugin::pushButton, rqt_gui_cpp::Plugin)

namespace rqt_plugin
{
    pushButton::pushButton()
    :   rqt_gui_cpp::Plugin()
    ,   widget_(0)
    {
    }

    void pushButton::initPlugin(qt_gui_cpp::PluginContext& context)
    {
        // Access standalone command line arguments
        QStringList argv = context.argv();

        // Create QWidget
        widget_ = new QWidget();

        // Extend the widget with all attributes and children from UI file
        ui_.setupUi(widget_);

        // add widget to the user interface
        context.addWidget(widget_);

        // ROS2 related declaration
        button1_pub_ = node_->create_publisher<std_msgs::msg::Bool>("button1", 1);
        button2_pub_ = node_->create_publisher<std_msgs::msg::Bool>("button2", 1);

        // Prepare msg
        msg_.data = true;

        // Connect with Qt Widget
        connect(ui_.pushButton_1, SIGNAL(pressed()), this, SLOT(button1Callback()));
        connect(ui_.pushButton_2, SIGNAL(pressed()), this, SLOT(button2Callback()));
    }

    void pushButton::shutdownPlugin()
    {
        ;
    }

    void pushButton::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
    {
        ;
    }

    void pushButton::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
    {
        ;
    }

    pushButton::~pushButton()
    {
        if(widget_)
            delete widget_;
    }

    void pushButton::button1Callback()
    {
        button1_pub_->publish(msg_);
    }

    void pushButton::button2Callback()
    {
        button2_pub_->publish(msg_);
    }

} // namespace rqt_plugin