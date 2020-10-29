#include "headers\Entity.hpp"
#include "headers\Component.hpp"

namespace engine 
{
    engine::Entity::Entity(string name, Scene* scene, Vector3 position, Vector3 rotation, Vector3 scale) :scene(scene), transform(std::shared_ptr<Transform_Component>(new Transform_Component( this, position, rotation, scale))), name(name)
    {
    }

    bool engine::Entity::initialize()
    {
        bool result = true;
        for (auto component : components)
        {
            if (component.second->initialize() == false)
            {
                result = false;
            }
        }

        return result;
    }

    bool engine::Entity::add_component(const string& type, shared_ptr<Component>& component)
    {
        if (components.count(type) != 0)
        {
            return false;
        }
        else
        {
            components[type] = component;
            return true;
        }
    }

    shared_ptr<Component> engine::Entity::get_component(string name_component)
    {
        if (name_component._Equal("transform"))
        {
            return transform;
        }
        if (!components[name_component]) 
        {
            return nullptr;
        }
       
        return components[name_component];
    }

    std::shared_ptr<glt::Node> engine::Entity::get_component_iterator(size_t i)
    {
        iterator_components = components.begin();
        for (size_t x = 0; x <= i; iterator_components++, x++);
        return iterator_components->second->get_node_component();
    }
}

