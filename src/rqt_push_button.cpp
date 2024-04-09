#include "ros2_rqt_plugin/rqt_push_button.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QStringList>
#include <qnamespace.h>

PLUGINLIB_EXPORT_CLASS(rqt_plugin::pushButton, rqt_gui_cpp::Plugin)

namespace rqt_plugin
{

  PushButtonWidget::PushButtonWidget(rclcpp::Node::SharedPtr node)
    : node_{node}
    , count_button_1_{0}
    , count_button_2_{0}
  {
    // Extend the widget with all attributes and children from UI file
    ui_.setupUi(this);

    // ROS2 related declaration
    button1_pub_ = node_->create_publisher<std_msgs::msg::Bool>("button1", 1);
    button2_pub_ = node_->create_publisher<std_msgs::msg::Bool>("button2", 1);

    // Prepare msg
    msg_.data = true;
  }

  PushButtonWidget::~PushButtonWidget() {}

  // Kindly refer to
  // https://github.com/BruceChanJianLe/ros2-actions/blob/50c05f4c2a6de6d82b60cf93059a206926edc2ab/rqt_move_base_client/src/rqt_move_base_client.cpp#L43
  // for more realistic example
  void PushButtonWidget::saveSettings([[maybe_unused]] qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
  {
    QVariant count_button_1 {count_button_1_};
    instance_settings.setValue({"count_button_1"}, count_button_1);

    QVariant count_button_2 {count_button_2_};
    instance_settings.setValue({"count_button_2"}, count_button_2);
  }

  // Kindly refer to
  // https://github.com/BruceChanJianLe/ros2-actions/blob/50c05f4c2a6de6d82b60cf93059a206926edc2ab/rqt_move_base_client/src/rqt_move_base_client.cpp#L52
  // for more realistic example
  void PushButtonWidget::restoreSettings([[maybe_unused]] const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
  {
    if (instance_settings.contains({"count_button_1"}))
    {
      QVariant count_button_1 {0};
      count_button_1 = instance_settings.value({"count_button_1"}, count_button_1);
      RCLCPP_INFO_STREAM(node_->get_logger(), "Button 1 was pressed " << count_button_1.toDouble() << " the last time.");
    }

    if (instance_settings.contains({"count_button_2"}))
    {
      QVariant count_button_2 {0};
      count_button_2 = instance_settings.value({"count_button_2"}, count_button_2);
      RCLCPP_INFO_STREAM(node_->get_logger(), "Button 2 was pressed " << count_button_2.toDouble() << " the last time.");
    }
  }

  void PushButtonWidget::on_pushButton1_clicked()
  {
    RCLCPP_INFO_STREAM(node_->get_logger(), "Published to button1 topic!");
    button1_pub_->publish(msg_);
    ui_.label_1->setText(QString::fromStdString({std::string{"Button 1 was clicked "} + std::to_string(++count_button_1_)}));
  }

  void PushButtonWidget::on_pushButton2_clicked()
  {
    RCLCPP_INFO_STREAM(node_->get_logger(), "Published to button2 topic!");
    button2_pub_->publish(msg_);
    ui_.label_2->setText(QString::fromStdString({std::string{"Button 2 was clicked "} + std::to_string(++count_button_2_)}));
  }

  pushButton::pushButton()
    : rqt_gui_cpp::Plugin()
    , widget_(0)
  {
  }

  void pushButton::initPlugin(qt_gui_cpp::PluginContext& context)
  {
    // Access standalone command line arguments
    QStringList argv = context.argv();

    // Create QWidget
    widget_ = new PushButtonWidget(node_);

    // add widget to the user interface
    context.addWidget(widget_);
  }

  pushButton::~pushButton()
  {
    if(widget_)
    {
      delete widget_;
    }
  }

  void pushButton::shutdownPlugin()
  {
  }

  void pushButton::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
  {
    if (widget_)
    {
      widget_->saveSettings(plugin_settings, instance_settings);
    }
  }

  void pushButton::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
  {
    if (widget_)
    {
      widget_->restoreSettings(plugin_settings, instance_settings);
    }
  }

} // namespace rqt_plugin
