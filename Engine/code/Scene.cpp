#pragma once
#include <Scene.hpp>
#include <Model_Component.hpp>
#include <Cube.hpp>
#include <Transform_Component.hpp>
#include <Entities_In_Game_Update.hpp>
#include <Sound_Component.hpp>

using namespace std;
namespace engine
{
    Scene::Scene(Window& window)
        :
        paint_task(this,1), 
        print_message_task(this, 3, "hola mundo"), 
        update_task(this,2), 
        handle(Dispacher::instance()),
        input_task(this,2), 
        control_task(this,2),
        ia_task(this,2),
        collision_task(this,2),
        script_task(this, 3)
    {
        count = 0;
        init_kernel(window);    

    }
    Scene::Scene(const string& scene_description_file_path, Window& window)
        :
        paint_task(this, 1),
        print_message_task(this, 3, "hola mundo"),
        update_task(this, 2),
        handle(Dispacher::instance()),
        input_task(this, 2),
        control_task(this, 2),
        ia_task(this, 2),
        collision_task(this, 2),
        script_task(this, 3)
    {
        //load(scene_description_file_path);
        count = 0;
        init_kernel(window);
    }

    void Scene::init_kernel(Window& window)
    {
        kernel = Kernel(window);
        kernel.add_task(paint_task);
        kernel.add_task(print_message_task);
        kernel.add_task(update_task);
        kernel.add_task(input_task);
        kernel.add_task(control_task);
        kernel.add_task(ia_task);
        kernel.add_task(collision_task);
        kernel.add_task(script_task);

       
    }

    void Scene::run()
    {
        
        kernel.execute();
        
    }
    ID Scene::add_entity(Entity& entity) 
    {
        entities[count] = &entity;
        return ++count;
    }
}