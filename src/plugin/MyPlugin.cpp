#include "plugin/MyPlugin.h"

#include <memory>

#include "ll/api/mod/NativeMod.h"
#include "ll/api/mod/RegisterHelper.h"

#include "ll/api/event/server/ServerStartedEvent.h"
#include "mc/world/level/levelgen/GeneratorType.h"
#include "more_dimensions/api/dimension/CustomDimensionManager.h"
#include "more_dimensions/api/dimension/SimpleCustomDimension.h"

namespace my_plugin {

static std::unique_ptr<MyPlugin> instance;

MyPlugin& MyPlugin::getInstance() { return *instance; }

bool MyPlugin::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the plugin goes here.
    return true;
}

bool MyPlugin::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the plugin goes here.

    more_dimensions::CustomDimensionManager::getInstance()
        .addDimension<more_dimensions::SimpleCustomDimension>("overworlddim", 345, GeneratorType::Overworld);

    return true;
}

bool MyPlugin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace my_plugin

LL_REGISTER_MOD(my_plugin::MyPlugin, my_plugin::instance);
