#include "headers\IA_Component.hpp"
#include <Entity.hpp>
#include <Transform_Component.hpp>

namespace engine 
{
    engine::IA_Component::IA_Component(Entity* parent) : Component(parent), target(nullptr)
    {
    }

    engine::IA_Component::IA_Component(Entity* target, Entity* parent) : Component(parent), target(target)
    {
    }

    void engine::IA_Component::set_new_target(glm::vec3 new_position)
    {
        position = new_position;
    }

    void engine::IA_Component::set_new_target(Entity* new_target)
    {
        target = new_target;
    }

    glm::vec3 engine::IA_Component::get_current_target_position()
    {
        if (target == nullptr)
            return position;
        else
        {
            return *dynamic_cast<Transform_Component*>(target->get_component("transform").get())->get_position();
        }
    }

    Entity* engine::IA_Component::get_target()
    {
        return target;
    }

    bool engine::IA_Component::initialize()
    {
        return true;
    }

    bool engine::IA_Component::parse_property(const string& name, const string& value)
    {
        return true;
    }

    string engine::IA_Component::get_type_component()
    {
        return "ia";
    }

    std::shared_ptr<glt::Node> engine::IA_Component::get_node_component()
    {
        return std::shared_ptr<glt::Node>();
    }

    std::shared_ptr<glt::Model> engine::IA_Component::get_model()
    {
        return std::shared_ptr<glt::Model>();
    }

    std::shared_ptr<glt::Light> engine::IA_Component::get_light()
    {
        return std::shared_ptr<glt::Light>();
    }

    std::shared_ptr<glt::Camera> engine::IA_Component::get_camera()
    {
        return std::shared_ptr<glt::Camera>();
    }

}
