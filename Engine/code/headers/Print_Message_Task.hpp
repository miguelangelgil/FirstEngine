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
#include <iostream>
#include <Task.hpp>
using namespace std;
namespace engine
{
    class Scene;
    class Print_Message_Task : public Task
    {
    private:
        /// <summary>
        /// Mensaje que queremos imprimir por pantalla
        /// </summary>
        string message;
    public:
        /// <summary>
        /// Constructor de tarea
        /// </summary>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="priority">prioridad de la tarea</param>
        /// <param name="message">mensaje</param>
        /// <returns></returns>
        Print_Message_Task(Scene* scene, int priority, string message);

        /// <summary>
        /// Inicializa la tarea
        /// </summary>
        /// <returns></returns>
        bool initialize() override;

        /// <summary>
        /// Finaliza la tarea
        /// </summary>
        /// <returns></returns>
        bool finalize() override;

        /// <summary>
        /// Imprime el mensaje en consola
        /// </summary>
        /// <param name="time">delta time</param>
        /// <returns></returns>
        bool step(double time) override;
    };

}