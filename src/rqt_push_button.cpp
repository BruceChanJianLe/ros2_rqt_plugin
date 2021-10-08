#include "ros2_rqt_plugin/rqt_push_button.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QStringList>

PLUGINLIB_EXPORT_CLASS(rqt_plugin::pushButton, rqt_gui_cpp::Plugin);

namespace rqt_plugin
{
    pushButton::pushButton()
    :   rqt_gui_cpp::Plugin()
    ,   widget_(0)
    {
    }

    void pushButton::initPlugin(qt_gui_cpp::PluginContext& context)
    {
        widget_ = new QWidget();
        ui_.setupUi(widget_);

        context.addWidget(widget_);
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
} // namespace rqt_plugin