#include "headers\IA_Controller_Task.hpp"
#include <Scene.hpp>
#include <IA_Component.hpp>
#include <Transform_Component.hpp>
namespace engine 
{
    engine::IA_Controller_Task::IA_Controller_Task(Scene* scene, int priority) : Task(scene, priority)
    {

    }

    bool engine::IA_Controller_Task::initialize()
    {
        scan_entities();
        active = true;
        return true;
    }

    bool engine::IA_Controller_Task::finalize()
    {
        active = false;
        return true;
    }

    bool engine::IA_Controller_Task::step(double time)
    {
        for (auto&& entity : entities) 
        {
            glm::vec3 target = dynamic_cast<IA_Component*>(entity->get_component("ia").get())->get_current_target_position();
            Transform_Component* transform = dynamic_cast<Transform_Component*>(entity->get_component("transform").get());
            glm::vec3 current_position = *transform->get_position();
            glm::vec3 translation(0.f,0.f,0.f);
            if (target.x > current_position.x) 
            {
                translation.x = 1.f * 0.003f;
            }
            else if (target.x < current_position.x) 
            {
                translation.x = - 1.f *0.003f;
            }

            if (target.y > current_position.y) 
            {
                translation.y = 1.f * 0.003f;
            }
            else if (target.y < current_position.y) 
            {
                translation.y = -1.f * 0.003f;
            }
            transform->set_traslate(translation);
        }
        return true;
    }

    void engine::IA_Controller_Task::scan_entities()
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
                if (iterator_components->second->get_type_component() == "ia")
                {
                    entities.push_back(iterator_entities->second);

                }
            }
        }
    }

}
