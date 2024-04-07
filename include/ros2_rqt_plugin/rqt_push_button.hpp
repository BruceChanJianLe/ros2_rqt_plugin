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

  // To use autoconnect signals and slots
  class PushButtonWidget : public QWidget
  {
  Q_OBJECT
  public:
    explicit PushButtonWidget(rclcpp::Node::SharedPtr node);
    virtual ~PushButtonWidget();

  private slots:
      void on_pushButton1_clicked();
      void on_pushButton2_clicked();

  private:
      rclcpp::Node::SharedPtr node_;

  protected:
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr button1_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr button2_pub_;
    std_msgs::msg::Bool msg_;
  };

  class pushButton : public rqt_gui_cpp::Plugin
  {
    Q_OBJECT
    public:
      pushButton();
      virtual ~pushButton();

      virtual void initPlugin(qt_gui_cpp::PluginContext& context) override;
      virtual void shutdownPlugin() override;
      virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const override;
      virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings) override;

    private:
      Ui::gui ui_;
      PushButtonWidget *widget_;
  };

}  // namespace rqt_plugin

#endif  // PUSH_BUTTON_H__
