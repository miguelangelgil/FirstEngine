#include "headers\Print_Message_Task.hpp"
#include <Scene.hpp>

engine::Print_Message_Task::Print_Message_Task(Scene* scene, int priority, string message) : Task(scene, priority)
{
    this->message = message;

}

bool engine::Print_Message_Task::initialize()
{
    active = true;
    return false;
}

bool engine::Print_Message_Task::finalize()
{
    active = false;
    return false;
}

bool engine::Print_Message_Task::step(double time)
{
    cout << message << endl;
    finalize();
    return false;
}
