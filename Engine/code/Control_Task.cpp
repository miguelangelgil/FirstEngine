#include "headers\Control_Task.hpp"
#include <Component.hpp>
#include <Scene.hpp>
#include <Input_Component.hpp>
#include <Transform_Component.hpp>
#include <Control_Component.hpp>
#include <Entity.hpp>
#include <Input.hpp>

namespace engine 
{
    Control_Task::Control_Task(Scene* scene, int priority) : Task(scene, priority)
    {
    }
    bool engine::Control_Task::initialize()
    {
        scan_components();
        active = true;
        return true;
    }

    bool engine::Control_Task::finalize()
    {
        active = false;
        return false;
    }

    bool engine::Control_Task::step(double time)
    {
        typedef shared_ptr<Component> component_ptr;
        for (auto&& control : components)
        {
            Input_Component* input = dynamic_cast<Input_Component*>(shared_ptr<Component>(control).get());
            Transform_Component* transform = dynamic_cast<Transform_Component*>(input->get_parent()->get_component("transform").get());
            Control_Component * control = dynamic_cast<Control_Component*>(input->get_parent()->get_component("control").get());
            glm::vec3 translation(0.f,0.f,0.f);
            if (input->keyboard->is_key_pressed(control->Up)) 
            {
                translation.y = 1.f;
            }
            else if (input->keyboard->is_key_pressed(control->Down)) 
            {
                translation.y = -1.f;
            }
            if (input->keyboard->is_key_pressed(control->Left)) 
            {
                translation.x = -1.f;
            }
            else if (input->keyboard->is_key_pressed(control->Right)) 
            {
                translation.x = 1.f;
            }

            transform->set_traslate(translation * control->speed);
           

        }
        return true;
    }

    void engine::Control_Task::add_Component(std::shared_ptr<Component> new_Component)
    {
        components.push_back(new_Component);
    }

    void engine::Control_Task::scan_components()
    {
        typedef shared_ptr<Component> component_ptr;
        map<string, component_ptr> ::iterator iterator_components;

        map<ID, Entity*>* scene_entities = scene->get_entities();
        map<ID, Entity*> ::iterator iterator_entities = scene_entities->begin();
        for (; iterator_entities != scene_entities->end(); iterator_entities++)
        {
            iterator_components = iterator_entities->second->get_components()->begin();
            for (; iterator_components != iterator_entities->second->get_components()->end(); iterator_components++)
            {
                if (iterator_components->second->get_type_component() == "input")
                {
                    components.push_back(iterator_components->second);

                }
            }
        }
    }

}
