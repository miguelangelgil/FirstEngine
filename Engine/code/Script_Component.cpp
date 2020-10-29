#include "Script_Component.hpp"

engine::Script_Component::Script_Component(Entity* parent) 
    :   Component(parent)
{}

bool engine::Script_Component::initialize()
{
    return false;
}

bool engine::Script_Component::parse_property(const string& name, const string& value)
{
    return false;
}

string engine::Script_Component::get_type_component()
{
    return "script";
}

std::shared_ptr<glt::Node> engine::Script_Component::get_node_component()
{
    return nullptr;
}

std::shared_ptr<glt::Model> engine::Script_Component::get_model()
{
    return std::shared_ptr<glt::Model>();
}

std::shared_ptr<glt::Light> engine::Script_Component::get_light()
{
    return std::shared_ptr<glt::Light>();
}

std::shared_ptr<glt::Camera> engine::Script_Component::get_camera()
{
    return std::shared_ptr<glt::Camera>();
}
