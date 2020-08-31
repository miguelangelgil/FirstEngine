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
#include <Component.hpp>

namespace engine 
{
    class Entity;
    class IA_Component : public Component
    {
    private:
        /// <summary>
        /// Puntero a la entidad que quieres seguir
        /// </summary>
        Entity* target;

        /// <summary>
        /// posicion a la que la ia se va a desplazar si no contiene un target
        /// </summary>
        glm::vec3 position;
    public:

        /// <summary>
        /// Constructor de clase 
        /// </summary>
        /// <param name="parent">entity padre del componente</param>
        /// <returns></returns>
        IA_Component(Entity * parent);

        /// <summary>
        /// Constructor de clase
        /// </summary>
        /// <param name="target">entidad que seguir</param>
        /// <param name="parent">entity padre del componente</param>
        /// <returns></returns>
        IA_Component(Entity * target, Entity * parent);

        /// <summary>
        /// Asigna una nueva posición a la que diriguirse
        /// </summary>
        /// <param name="new_position">punto al que diriguirse</param>
        void set_new_target(glm::vec3 new_position);

        /// <summary>
        /// Asigna un nuevo target al que seguir
        /// </summary>
        /// <param name="new_target">entity a la que seguir</param>
        void set_new_target(Entity * new_target);

        /// <summary>
        /// Retorna la posición a la que se dirige la entidad
        /// </summary>
        /// <returns></returns>
        glm::vec3 get_current_target_position();

        /// <summary>
        /// Retornal la entidad targeteada
        /// </summary>
        /// <returns>retorna la entity</returns>
        Entity * get_target();

        // Heredado vía Component

        /// <summary>
        /// Inicializa los parámetros necesários
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() override;

        /// <summary>
        /// Parsea parametros a las variables indicadas
        /// </summary>
        /// <param name="name">parametro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        virtual bool parse_property(const string& name, const string& value) override;

        /// <summary>
        /// Retorna el tipo de componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        virtual string get_type_component() override;

        /// <summary>
        /// Retorna un puntero al nodo que contiene el componente
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        virtual std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Retorna un puntero al nodo Model 
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        virtual std::shared_ptr<glt::Model> get_model() override;

        /// <summary>
        /// Retorna un puntero al nodo Light 
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        virtual std::shared_ptr<glt::Light> get_light() override;

        /// <summary>
        /// Retorna un puntero al nodo Camera
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        virtual std::shared_ptr<glt::Camera> get_camera() override;
    };
}
