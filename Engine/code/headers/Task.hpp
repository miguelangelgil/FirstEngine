/*
MIT License

Copyright(c) 2020 MAGMa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
//#include "Kernel.hpp"
#include <Window.hpp>
#include <Component.hpp>
#include <list>
// Tareas consumibles o no consumibles
// Secuancia de tareas (hereda de task y tiene una lista de tasks)


namespace engine
{
    using namespace std;
    class Kernel;
    class Scene;

    class Task
    {

    public:

        typedef shared_ptr <Component> component_ptr;
        /// <summary>
        /// Lista de componentes con los que va ha operar las tasks
        /// </summary>
        list<component_ptr> components;

        /// <summary>
        /// Puntero al kernel
        /// </summary>
        Kernel* kernel;

        /// <summary>
        /// Puntero a la escena
        /// </summary>
        Scene* scene;

        /// <summary>
        /// Indicador de prioridad de la tarea
        /// </summary>
        int priority;

        /// <summary>
        /// Indica el estado de la tarea
        /// </summary>
        bool active;

    public:
        /// <summary>
        /// Constructor de la tarea
        /// </summary>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="priority">prioridad de la tarea siendo 0 la maxima</param>
        /// <returns></returns>
        Task(Scene* scene, int priority);

        /// <summary>
        /// Destructor de tarea
        /// </summary>
        /// <returns></returns>
        virtual ~Task() = default;

        /// <summary>
        /// Setea un kernel
        /// </summary>
        /// <param name="new_kernel"></param>
        void set_kernel(Kernel& new_kernel);

    public:
        /// <summary>
        /// Funcion virtual pura que inicializa la tarea
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() = 0;
        /// <summary>
        /// Funcion virtual pura que finaliza la tarea
        /// </summary>
        /// <returns></returns>
        virtual bool finalize() = 0;
        /// <summary>
        /// Funcion virtual pura que ejecuta la tarea
        /// </summary>
        /// <param name="time"></param>
        /// <returns></returns>
        virtual bool step(double time) = 0;
        

    public:
        /// <summary>
        /// compara tareas por prioridad
        /// </summary>
        /// <param name="other">otra tarea</param>
        /// <returns>es mas prioritario</returns>
        bool operator < (const Task& other) const
        {
            return this->priority < other.priority;
        }
        /// <summary>
        /// Retorna si una tarea esta activa
        /// </summary>
        /// <returns>esta activa</returns>
        bool active_task()
        {
            return active;
        }
       
    };

}
