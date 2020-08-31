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

namespace engine 
{
    class Scene;
    class Input_Task : public Task
    {
    public:
        /// <summary>
        /// Constructor de la tarea
        /// </summary>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="priority">prioridad de la tarea</param>
        /// <returns></returns>
        Input_Task(Scene* scene, int priority);
        // Heredado vía Task

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
        /// Comprueba los inputs del teclado y envía mensajes de los eventos
        /// </summary>
        /// <param name="time"></param>
        /// <returns></returns>
        virtual bool step(double time) override;
    };
}

