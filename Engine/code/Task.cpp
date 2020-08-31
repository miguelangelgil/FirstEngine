#include "headers\Task.hpp"
#include "headers/Scene.hpp"
#include "headers/Kernel.hpp"

engine::Task::Task(Scene* scene, int priority) :priority(priority), scene(scene), active(false)
{
    kernel = nullptr;
}

void engine::Task::set_kernel(Kernel& new_kernel)
{
    kernel = &new_kernel;
}
