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
#include <EngineTypeDef.hpp>
#include <Node.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Camera.hpp>

using namespace std;

namespace engine
{
    class Entity;
    class Component
    {
    protected:
        /// <summary>
        /// puntero al padre que lo contiene
        /// </summary>
        Entity* parent;

    public:
        /// <summary>
        /// Constructor de Componente
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <returns></returns>
        Component(Entity* parent);

        /// <summary>
        /// destructor de componente
        /// </summary>
        /// <returns></returns>
        virtual ~Component();

        /// <summary>
        /// Funcion virtual pura que inicializa el componente
        /// </summary>
        /// <returns>retorna si la operación se ha efectuado con exito</returns>
        virtual bool initialize() = 0;

        /// <summary>
        /// Funcion virtual pura que recive unos strings e inicializa los parámetros de los componentes
        /// </summary>
        /// <param name="name">nombre del parámetro</param>
        /// <param name="value">valor del parametro</param>
        /// <returns>retorna si la operación se ha realizado con exito</returns>
        virtual bool parse_property
        (
            const string& name,
            const string& value
        ) = 0;

        /// <summary>
        /// Funcion virtual pura que indica el tipo de componente 
        /// </summary>
        /// <returns>retorna una cadena de texto que indica el tipo de componente</returns>
        virtual string get_type_component() = 0;

        /// <summary>
        /// Funcion virtual pura que retorna el nodo que contiene
        /// </summary>
        /// <returns>Retorna el nodo</returns>
        virtual std::shared_ptr<glt::Node> get_node_component() = 0;
        /// <summary>
        /// Funcion virtual pura que devuelve el nodo modelo
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        virtual std::shared_ptr<glt::Model> get_model() = 0;
        /// <summary>
        /// Funcion virtual pura que devuelve el nodo luz
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        virtual std::shared_ptr<glt::Light> get_light() = 0;
        /// <summary>
        /// Funcion virtual pura que devuelve el nodo camara
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        virtual std::shared_ptr<glt::Camera> get_camera() = 0;

        /// <summary>
        /// Devuelve el puntero a la entidad padre
        /// </summary>
        /// <returns>entity padre del componente</returns>
        Entity* get_parent() 
        {
            return parent;
        }

    };

}
