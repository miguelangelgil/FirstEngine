#include "headers\Collision_Task.hpp"
#include <Scene.hpp>
#include <Entity.hpp>
#include <Sphere_Collider_Component.hpp>
#include <Transform_Component.hpp>
#include <Sound_Component.hpp>
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
        for (size_t i=0;i < entities_sphere_collision.size();i++) 
        {
            for (size_t other = 0; other < entities_sphere_collision.size(); other++) 
            {
                if (i != other) 
                {
                    glm::vec3 current_position = *dynamic_cast<Transform_Component*>(entities_sphere_collision[i]->get_component("transform").get())->get_position();
                    glm::vec3 other_position = *dynamic_cast<Transform_Component*>(entities_sphere_collision[other]->get_component("transform").get())->get_position();
                    //float current_radius = dynamic_cast<Sphere_Collider_Component*>(entities_sphere_collision[i]->get_component("collision").get())->radius;
                    //float other_radius = dynamic_cast<Sphere_Collider_Component*>(entities_sphere_collision[other]->get_component("collision").get())->radius;
                    float distance = sqrt(pow((other_position.x - current_position.x), 2) + pow((other_position.y - current_position.y), 2) + pow((other_position.z - current_position.z), 2));
                    if (distance < 2.f/*current_radius + other_radius*/) 
                    {
                        if (entities_sphere_collision[i] == player || entities_sphere_collision[other] == player)
                        {
                           dynamic_cast<Sound_Component*> (player->get_component("choque_sound").get())->play(100,1);
                        }
                      
                    }
                }
            }
        }
        return false;
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

