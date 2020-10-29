#include "headers\Sphere_Collider_Component.hpp"
namespace engine 
{
    engine::Sphere_Collider_Component::Sphere_Collider_Component(Entity* parent, float radius) : Component(parent)
    {
        this->radius = radius;
    }

    bool engine::Sphere_Collider_Component::initialize()
    {
        collision_state = COLLISION_STATE::OUT_COLLISION;
        return true;
    }

    bool engine::Sphere_Collider_Component::parse_property(const string& name, const string& value)
    {
        return true;
    }

    string engine::Sphere_Collider_Component::get_type_component()
    {
        return "collider";
    }

    std::shared_ptr<glt::Node> engine::Sphere_Collider_Component::get_node_component()
    {
        return std::shared_ptr<glt::Node>();
    }

    std::shared_ptr<glt::Model> engine::Sphere_Collider_Component::get_model()
    {
        return std::shared_ptr<glt::Model>();
    }

    std::shared_ptr<glt::Light> engine::Sphere_Collider_Component::get_light()
    {
        return std::shared_ptr<glt::Light>();
    }

    std::shared_ptr<glt::Camera> engine::Sphere_Collider_Component::get_camera()
    {
        return std::shared_ptr<glt::Camera>();
    }

    string engine::Sphere_Collider_Component::get_type_collider()
    {
        return "sphere";
    }

}
