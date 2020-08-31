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
#include <Task.hpp>
#include <Model_Component.hpp>
#include <Kernel.hpp>
#include <list>
#include <Render_Node.hpp>
using namespace std;
using namespace glt;

namespace engine
{
    class Entity;
    class Scene;
    class Update_Positions_Task : public Task
    {
    private:
        /// <summary>
        /// Vector de puntero a entidades que necesitan actualizar su posicion
        /// </summary>
        vector<Entity*> entities;
        /// <summary>
        /// Iterador de mapa de componentes
        /// </summary>
        std::map<string, component_ptr>::iterator iterator_components;
    public:
        /// <summary>
        /// Constructor de tarea
        /// </summary>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="priority">prioridad de la tarea</param>
        /// <returns></returns>
        Update_Positions_Task(Scene* scene, int priority);
       
        /// <summary>
        /// Inicializa la tarea
        /// </summary>
        /// <returns></returns>
        bool initialize() override;

        /// <summary>
        /// Finaliza la tarae
        /// </summary>
        /// <returns></returns>
        bool finalize() override;

        /// <summary>
        /// Actualiza la posición de la estidades
        /// </summary>
        /// <param name="time"></param>
        /// <returns></returns>
        bool step(double time) override;

        /// <summary>
        /// Anyade un componente 
        /// </summary>
        /// <param name="new_Component">componente</param>
        void add_Component(std::shared_ptr<Component> new_Component);

        /// <summary>
        /// Escanea las entidades en busca de entidades con trasnform
        /// </summary>
        void scan_entities();
    };
}

