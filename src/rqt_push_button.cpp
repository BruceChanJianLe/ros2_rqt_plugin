#include "ros2_rqt_plugin/rqt_push_button.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QStringList>

PLUGINLIB_EXPORT_CLASS(rqt_plugin::pushButton, rqt_gui_cpp::Plugin);

namespace rqt_plugin
{
    pushButton::pushButton()
    :   rqt_gui_cpp::Plugin()
    {
    }

    pushButton::~pushButton()
    {
    }

    void pushButton::initPlugin(qt_gui_cpp::PluginContext& context)
    {
        ;
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

} // namespace rqt_plugin