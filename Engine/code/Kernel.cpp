#pragma once
#include <Window.hpp>
#include <Kernel.hpp>
#include <Task.hpp>
#include <SDL_thread.h>
#include <Transform_Component.hpp>
#include <Scene.hpp>
#include <Entities_In_Game_Update.hpp>

namespace engine
{

    Kernel::Kernel(Window& other)
    {
        this->window = &other;
        exit = false;
        paused = false;

    }
    void Kernel::add_task(Task& task)
    {
        task.set_kernel(*this);
        tasks.insert(&task);
        
    }
    void Kernel::add_list_updates(Kernel::Update_Element_List list)
    {
        update_element_list = list;
    }

    void Kernel::execute()
    {
        exit = false;

        for (auto task : tasks)
        {
            task->initialize();
        }

        delta_time = 1.0L / 60.0L;

        do
        {
            timer = std::chrono::high_resolution_clock::now();

            for (auto task : tasks)
            {
                if (exit)
                {
                    break;
                }
                else if (paused)
                {
                    while (paused)
                    {
                        // Thread::current_thread().sleep(10);
                    }
                }
                if(task->active_task())
                    task->step(delta_time);  // Hacer una barra de carga
            }
            for (auto update : update_element_list) 
            {
                update->Update(delta_time);
            }
            delta_time = (long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - timer).count();
        } while (!exit);
        for (Task* t : tasks)
        {
            t->finalize();
        }
    }

    void Kernel::stop()
    {
        exit = true;
    }

    void Kernel::pause()
    {
        paused = true;
    }

    void Kernel::resume()
    {
        paused = false;
    }

    Window& Kernel::get_window()
    {
        return *window;
    }

}