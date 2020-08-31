#include "headers\Light_Component.hpp"
#include <Entity.hpp>

namespace engine
{
    engine::Light_Component::Light_Component(Entity* parent) : Component(parent), light(new glt::Light())
    {
        initialize();
    }

    bool engine::Light_Component::initialize()
    {
        Transform_Component* transform = dynamic_cast<Transform_Component*>(parent->get_component("transform").get());
        transform->set_Transform(light);
        transform->apply_Transform();
        return false;
    }

    std::shared_ptr<glt::Light> engine::Light_Component::get_Light()
    {
        return light;
    }

    bool engine::Light_Component::parse_property(const string& name, const string& value)
    {
        return false;
    }

    string engine::Light_Component::get_type_component()
    {
        return "light";
    }

    std::shared_ptr<glt::Node> engine::Light_Component::get_node_component()
    {
        return light;
    }

    std::shared_ptr<Model> engine::Light_Component::get_model()
    {
        return std::shared_ptr<Model>();
    }

    std::shared_ptr<Light> engine::Light_Component::get_light()
    {
        return light;
    }

    std::shared_ptr<Camera> engine::Light_Component::get_camera()
    {
        return std::shared_ptr<Camera>();
    }


}
