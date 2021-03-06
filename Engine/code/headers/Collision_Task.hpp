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
#include <iostream>
#include <vector>

using namespace std;
namespace engine 
{
    class Entity;
    class Scene;
    class Collision_Task : public Task 
    {
    private:
        /// <summary>
        /// Lista de entidades que contienen un collider esferico
        /// </summary>
        vector<Entity*> entities_sphere_collision;
        /// <summary>
        /// Puntero a la entidad del player, se usa esta referencia para realizar una tarea al chocar con el
        /// </summary>
        Entity* player;
        /// <summary>
        /// Determina si el jugador se encuentra dentro de una colision
        /// </summary>
        bool player_in_collision;
    public:
        /// <summary>
        /// Constructor de tarea
        /// </summary>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="priority">prioridad</param>
        /// <returns></returns>
        Collision_Task(Scene * scene, int priority);
        // Heredado v�a Task
        
        /// <summary>
        /// Inicializa la tarea
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() override;
        /// <summary>
        /// Finaliza la tarea
        /// </summary>
        /// <returns></returns>
        virtual bool finalize() override;
        /// <summary>
        /// Calcula las colisiones de los elementos de la lista, si en las colisiones se encuentra un player
        ///se reproduce un sonido del componente de sound del player
        /// </summary>
        /// <param name="time"></param>
        /// <returns></returns>
        virtual bool step(double time) override;

        /// <summary>
        /// Escanea las entidades de la escena y guarda aquellas que contengan collider
        /// </summary>
        void scan_components();
    };
}
