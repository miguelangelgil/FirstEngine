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
// & direccion / * referencia

#include <set>
#include <chrono>
#include <Entities_In_Game_Update.hpp>


namespace engine
{
    class Scene;
    class Task;
    class Window;

    class Kernel
    {
        /// <summary>
        /// Tipo de lista de tareas
        /// </summary>
        typedef std::multiset< Task* > Task_List;
        /// <summary>
        /// Tiempo inicial
        /// </summary>
        std::chrono::high_resolution_clock::time_point start_time;
        /// <summary>
        /// Tiempo auxiliar
        /// </summary>
        std::chrono::high_resolution_clock::time_point timer;
        /// <summary>
        /// Tiempo trascurrido entre fotogramas
        /// </summary>
        long double delta_time = .0;

        typedef std::multiset< Entities_In_Game_Update* > Update_Element_List;
        /// <summary>
        /// Lista de elementos que hay que actualizar
        /// </summary>
        Update_Element_List update_element_list;

        /// <summary>
        /// Puntero a la ventana
        /// </summary>
        Window* window;
        /// <summary>
        /// Lista de tareas
        /// </summary>
        Task_List tasks;
        /// <summary>
        /// Puntero a la escena
        /// </summary>
        Scene* scene;

        /// <summary>
        /// indicador de si esta pausado
        /// </summary>
        bool paused;
        /// <summary>
        /// controlador de salida
        /// </summary>
        bool exit;

    public:
        /// <summary>
        /// Constructor del Kernel
        /// </summary>
        /// <param name="other">ventana</param>
        /// <returns></returns>
        Kernel(Window& other);
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        /// <returns></returns>
        Kernel() = default;

        ~Kernel() = default;
        /// <summary>
        /// Constructor de copia
        /// </summary>
        /// <param name="other">referencia de otro kernel</param>
        /// <returns></returns>
        Kernel(Kernel& other) = default;

        /// <summary>
        /// Anyade una tarea
        /// </summary>
        /// <param name="task"></param>
        void add_task(Task& task);

        /// <summary>
        /// Aniade un elemento a actualizar
        /// </summary>
        /// <param name="list"></param>
        void add_list_updates(Update_Element_List list);

        /// <summary>
        /// bucle principal del motor
        /// </summary>
        void execute();

        /// <summary>
        /// Finaliza el programa
        /// </summary>
        void stop();

        /// <summary>
        /// Para la ejecucion
        /// </summary>
        void pause();

        /// <summary>
        /// Reanuda la ejecucion
        /// </summary>
        void resume();

        /// <summary>
        /// Retorna la ventana
        /// </summary>
        /// <returns></returns>
        Window& get_window();

    };
}

