#include "headers\Camera_Component.hpp"
#include "headers/Entity.hpp"

namespace engine 
{
    engine::Camera_Component::Camera_Component(Entity* parent) : Component(parent),camera(new glt::Camera(20.f, 1.f, 50.f, 1.f))
    {
        initialize();
    }

    bool engine::Camera_Component::initialize()
    {
        Transform_Component* transform = dynamic_cast<Transform_Component*>(parent->get_component("transform").get());
        transform->set_Transform(camera);
        transform->apply_Transform();
        return false;
    }

    bool engine::Camera_Component::parse_property(const string& name, const string& value)
    {
        return false;
    }

    string engine::Camera_Component::get_type_component()
    {
        return "camera";
    }

    std::shared_ptr<glt::Node> engine::Camera_Component::get_node_component()
    {
        return camera;
    }

    void engine::Camera_Component::look_at(const glt::Vector3& where)
    {
        look_at(where);
    }

    std::shared_ptr<glt::Model> engine::Camera_Component::get_model()
    {
        return std::shared_ptr<glt::Model>();
    }

    std::shared_ptr<glt::Light> engine::Camera_Component::get_light()
    {
        return std::shared_ptr<glt::Light>();
    }

    std::shared_ptr<glt::Camera> engine::Camera_Component::get_camera()
    {
        return camera;
    }

}
