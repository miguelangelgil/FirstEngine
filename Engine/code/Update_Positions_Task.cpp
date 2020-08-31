#include <Update_Positions_Task.hpp>
#include <Scene.hpp>
#include <Transform_Component.hpp>
#include <Camera.hpp>
#include <Kernel.hpp>
#include <glad/glad.h>
#include <Model_Component.hpp>
#include <Entity.hpp>


namespace engine
{
    Update_Positions_Task::Update_Positions_Task(Scene* scene, int priority) : Task(scene, priority)
    {
    }

    bool Update_Positions_Task::initialize()
    {
        scan_entities();
        active = true;
        for (auto& component : components) {
            component->initialize();
        }
        return false;


    }

    bool Update_Positions_Task::finalize()
    {
        active = false;
       
        return false;
    }

    bool Update_Positions_Task::step(double time)
    {
        for (size_t i = 0; i < entities.size(); i++) 
        {
            Transform_Component* transform = dynamic_cast<Transform_Component*>(entities[i]->get_component("transform").get());
            transform->apply_Transform();
            iterator_components = entities[i]->get_components()->begin();
            for (; iterator_components != entities[i]->get_components()->end(); iterator_components++)
            {
                if (iterator_components->second->get_node_component() != nullptr) 
                {
                    iterator_components->second->get_node_component()->set_transformation(transform->get_transformation());
                    
                }
               
            }
        }
        return false;
    }

    void Update_Positions_Task::add_Component(std::shared_ptr<Component> new_Component)
    {
        components.push_back(new_Component);
    }

    void Update_Positions_Task::scan_entities()
    {
        map<ID, Entity*>* scene_entities = scene->get_entities();
        map<ID, Entity*> ::iterator iterator_entities = scene_entities->begin();
        for (; iterator_entities != scene_entities->end(); iterator_entities++)
        {
            entities.push_back(iterator_entities->second);
           
        }

    }
}