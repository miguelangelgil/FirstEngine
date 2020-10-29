#include "Script_Task.hpp"
#include <Scene.hpp>
#include <Script_Component.hpp>

void engine::Script_Task::scan_entities()
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
            if (iterator_components->second->get_type_component() == "script")
            {
                entities.push_back(iterator_entities->second);

            }
        }
    }
}

engine::Script_Task::Script_Task(Scene* scene, int priority)
    :   Task(scene, priority)
{
}

bool engine::Script_Task::initialize()
{
    scan_entities();
    active = true;
    for (auto&& entity : entities) 
    {
        dynamic_cast<Script_Component*>(entity->get_component("script").get())->Start();
    }
    return true;
}

bool engine::Script_Task::finalize()
{
    return false;
}

bool engine::Script_Task::step(double time)
{
    for (auto&& entity : entities)
    {
        dynamic_cast<Script_Component*>(entity->get_component("script").get())->Update(time);
    }

    return true;
}
