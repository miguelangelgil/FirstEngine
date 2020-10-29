#include "headers\Collision_Task.hpp"
#include <Scene.hpp>
#include <Entity.hpp>
#include <Sphere_Collider_Component.hpp>
#include <Transform_Component.hpp>
#include <Sound_Component.hpp>
#include <Script_Component.hpp>
#include <math.h>

namespace engine 
{
    engine::Collision_Task::Collision_Task(Scene* scene, int priority) : Task(scene, priority)
    {
    }

    bool engine::Collision_Task::initialize()
    {
        scan_components();
        active = true;
        return true;
    }

    bool engine::Collision_Task::finalize()
    {
        active = false;
        return true;
    }

    bool engine::Collision_Task::step(double time)
    {
        bool collision;
        for (size_t i=0;i < entities_sphere_collision.size();i++) 
        {
            Sphere_Collider_Component* collision_component = dynamic_cast<Sphere_Collider_Component*>(entities_sphere_collision[i]->get_component("collider").get());
            collision = false;
            size_t other;
            for (other = 0; other < entities_sphere_collision.size(); other++) 
            {
                if (i != other) 
                {
                    glm::vec3 current_position = *dynamic_cast<Transform_Component*>(entities_sphere_collision[i]->get_component("transform").get())->get_position();
                    glm::vec3 other_position = *dynamic_cast<Transform_Component*>(entities_sphere_collision[other]->get_component("transform").get())->get_position();
                    float distance = sqrt(pow((other_position.x - current_position.x), 2) + pow((other_position.y - current_position.y), 2) + pow((other_position.z - current_position.z), 2));
                    if (distance < collision_component->radius + dynamic_cast<Sphere_Collider_Component*>(entities_sphere_collision[i]->get_component("collider").get())->radius)
                    {
                        collision = true;
                        break;
                    }
                }
            }
            if (collision)
            {
                switch (collision_component->get_state_collision())
                {
                case COLLISION_STATE::OUT_COLLISION:
                    collision_component->set_state_collision(COLLISION_STATE::ON_COLLISION_ENTER);
               
                    break;
                case COLLISION_STATE::ON_COLLISION_ENTER:
                    collision_component->set_state_collision(COLLISION_STATE::ON_COLLISION);
            
                    break;
                case COLLISION_STATE::ON_COLLISION_EXIT:
                    collision_component->set_state_collision(COLLISION_STATE::ON_COLLISION_ENTER);
            
                    break;
                }
            }
            else 
            {
                switch (collision_component->get_state_collision())
                {
               
                case COLLISION_STATE::ON_COLLISION_ENTER:
                    collision_component->set_state_collision(COLLISION_STATE::ON_COLLISION_EXIT);
                    break;
                case COLLISION_STATE::ON_COLLISION:
                    collision_component->set_state_collision(COLLISION_STATE::ON_COLLISION_EXIT);
                    break;
                case COLLISION_STATE::ON_COLLISION_EXIT:
                    collision_component->set_state_collision(COLLISION_STATE::OUT_COLLISION);
                    break;
                }

            }
            if(other < entities_sphere_collision.size())
                if (dynamic_cast<Script_Component*>(entities_sphere_collision[i]->get_component("script").get()))
                    dynamic_cast<Script_Component*>(entities_sphere_collision[i]->get_component("script").get())->OnCollision(entities_sphere_collision[other], collision_component->get_state_collision());
        }

        return true;
    }

    void engine::Collision_Task::scan_components()
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
                if (iterator_components->second->get_type_component() == "collider")
                {
                    if(dynamic_cast<Sphere_Collider_Component*>(iterator_components->second.get())->get_type_collider() == "sphere")
                        entities_sphere_collision.push_back(iterator_entities->second);

                }
                if (iterator_components->second->get_type_component() == "sound") 
                {
                    player = iterator_entities->second;
                }
            }
        }
    }

}

