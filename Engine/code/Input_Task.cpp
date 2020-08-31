#include "headers\Input_Task.hpp"
#include <Message.hpp>
#include <Scene.hpp>
#include <Dispacher.hpp>
#include <SDL.h>

namespace engine 
{
    engine::Input_Task::Input_Task(Scene* scene, int priority) : Task(scene, priority)
    {
    }

    bool engine::Input_Task::initialize()
    {
        active = true;
        return true;
    }

    bool engine::Input_Task::finalize()
    {
        active = false;
        return false;
    }

    bool engine::Input_Task::step(double time)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) > 0) 
        {
            if (event.type == SDL_QUIT) 
            {

            }
            else if (event.type == SDL_KEYDOWN) 
            {
                Message message("Keyboard");
                message.add_parameter("KeyDown", SDL_GetKeyName(event.key.keysym.sym));
                scene->get_message_handle()->send(message);
                
            }
            else if (event.type == SDL_KEYUP) 
            {
                Message message("Keyboard");
                message.add_parameter("KeyUp", SDL_GetKeyName(event.key.keysym.sym));
                scene->get_message_handle()->send(message);
            }
        }
        return true;
    }

}
