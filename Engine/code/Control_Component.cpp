#include "headers\Control_Component.hpp"

engine::Control_Component::Control_Component(Entity* entity) : Component(entity), speed(1.f), JumpForce(1.f)
{
    initialize();
}

bool engine::Control_Component::initialize()
{
    Up =    "W";
    Down =  "S";
    Left =  "A";
    Right = "D";
    speed = 0.01f;
    return true;
}

bool engine::Control_Component::parse_property(const string& name, const string& value)
{
    if (name == "Up")
        Up = value;
    else  if (name == "Down")
        Down = value;
    else  if (name == "Left")
        Left = value;
    else  if (name == "Right")
        Right = value;
    else  if (name == "Jump")
        Jump = value;
    else if (name == "speed")
        speed = stof(value);
    else if (name == "JumpForce")
        JumpForce = stof(value);

    return true;
}

string engine::Control_Component::get_type_component()
{
    return "control";
}

std::shared_ptr<glt::Node> engine::Control_Component::get_node_component()
{
    return std::shared_ptr<glt::Node>();
}

std::shared_ptr<glt::Model> engine::Control_Component::get_model()
{
    return std::shared_ptr<glt::Model>();
}

std::shared_ptr<glt::Light> engine::Control_Component::get_light()
{
    return std::shared_ptr<glt::Light>();
}

std::shared_ptr<glt::Camera> engine::Control_Component::get_camera()
{
    return std::shared_ptr<glt::Camera>();
}
