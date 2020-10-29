#pragma once
#include <Task.hpp>
#include <vector>
namespace engine 
{
    class Script_Task : public Task 
    {
    private:
        std::vector<Entity*> entities;
    public:
        /// <summary>
       /// Escanea las entidades de la escena en busca de entidades con el componente Script
       /// </summary>
        void scan_entities();
    public:
        Script_Task(Scene* scene, int priority);

        // Heredado vía Task
        virtual bool initialize() override;
        virtual bool finalize() override;
        virtual bool step(double time) override;
    };
}
