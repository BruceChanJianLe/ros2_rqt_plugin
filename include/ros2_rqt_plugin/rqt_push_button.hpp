#ifndef PUSH_BUTTON_H__
#define PUSH_BUTTON_H__

// ROS2
#include <rclcpp/rclcpp.hpp>

// msgs
#include <std_msgs/msg/bool.hpp>

// Rqt
#include <rqt_gui_cpp/plugin.h>

// Qt
#include <QWidget>

// Custom UI
#include <ros2_rqt_plugin/ui_rqt_push_button.h>

namespace rqt_plugin
{
  class pushButton : public rqt_gui_cpp::Plugin
  {
    Q_OBJECT
    public:
      pushButton();

      virtual void initPlugin(qt_gui_cpp::PluginContext& context) override;

      virtual void shutdownPlugin() override;

      virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const override;

      virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings) override;

      virtual ~pushButton();

      private:
        Ui::gui ui_;
        QWidget * widget_;

      protected:
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr button1_pub_;
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr button2_pub_;
        std_msgs::msg::Bool msg_;
      
      protected slots:
        void button1Callback();
        void button2Callback();
  };
}  // namespace rqt_plugin

#endif  // PUSH_BUTTON_H__
