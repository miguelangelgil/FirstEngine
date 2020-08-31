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
#include <memory>
#include <map>
#include <Kernel.hpp>
#include <Entity.hpp>
#include <chrono>
#include <Window.hpp>
#include <Model.hpp>
#include <Model_Component.hpp>
#include <Dispacher.hpp>
#include <Paint_Task.hpp>
#include <Print_Message_Task.hpp>
#include <Update_Positions_Task.hpp>
#include <Input_Task.hpp>
#include <Collision_Task.hpp>
#include <Control_Task.hpp>
#include <IA_Controller_Task.hpp>

//#include <Entities_In_Game_Update.hpp>
using namespace std;
namespace engine
{
    class Task;
    class Scene
    {
        /// <summary>
        /// Tarea de pintar mensaje
        /// </summary>
        Print_Message_Task print_message_task;
        /// <summary>
        /// Tarea de renderizado
        /// </summary>
        Paint_Task paint_task;
        /// <summary>
        /// Tarea de actualizacion de posiciones
        /// </summary>
        Update_Positions_Task update_task;
        /// <summary>
        /// Traea de deteccion de inputs
        /// </summary>
        Input_Task input_task;
        /// <summary>
        /// Tarea de control del jugador
        /// </summary>
        Control_Task control_task;
        /// <summary>
        /// Tarea de control de ia
        /// </summary>
        IA_Controller_Task ia_task;
        /// <summary>
        /// Traea de deteccion de colisiones
        /// </summary>
        Collision_Task collision_task;

        /// <summary>
        /// kernel 
        /// </summary>
        Kernel     kernel;
        /// <summary>
        /// shared_ptr al dispacher para enviar mensajes de eventos
        /// </summary>
        shared_ptr<Dispacher>  handle;
        typedef std::multiset< Entities_In_Game_Update* > Update_Element_List;
        /// <summary>
        /// Lista de elementos a actualizar
        /// </summary>
        Update_Element_List update_element_list;

    public:
        /// <summary>
        /// Entidades de la escena
        /// </summary>
        map<ID, Entity*> entities;
        /// <summary>
        /// Constructor de la escena
        /// </summary>
        /// <param name="window">ventana</param>
        /// <returns></returns>
        Scene(Window& window);
        /// <summary>
        /// Constructor de la escena mediante un xml
        /// </summary>
        /// <param name="scene_description_file_path">fichero de carga de escena</param>
        /// <param name="window">ventana</param>
        /// <returns></returns>
        Scene(const string& scene_description_file_path, Window& window);

    private:
        /// <summary>
        /// Cnatidad de entidades
        /// </summary>
        ID count;
        /// <summary>
        /// Inicializa el kernel
        /// </summary>
        /// <param name="window">ventana</param>
        void init_kernel(Window& window);

    public:
        /// <summary>
        /// Incia la escena y el bucle principal del kernel
        /// </summary>
        void run();
        /// <summary>
        /// Anyade una entidad a la escena
        /// </summary>
        /// <param name="entity">entidad</param>
        /// <returns></returns>
        ID add_entity(Entity& entity);
        /// <summary>
        /// Aniade elemento a actualizar
        /// </summary>
        /// <param name="update_element"></param>
        void add_update(Entities_In_Game_Update* update_element) 
        {
            update_element_list.insert(update_element);
        }
        /// <summary>
        /// Retorna el mapa de entidades
        /// </summary>
        /// <returns></returns>
        map<ID, Entity*>* get_entities() 
        {
            return &entities;
        }
        /// <summary>
        /// Retorna el handle
        /// </summary>
        /// <returns></returns>
        shared_ptr<Dispacher> get_message_handle()
        {
           return handle;
        }

    };

}
