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
#include<Component.hpp>
#include<Render_Node.hpp>
#include <Math.hpp>
#include <Light.hpp>
#include <Transform_Component.hpp>
using namespace std;
using namespace glt;
namespace engine
{
    class Entity;
    class Light_Component : public Component
    {
    private:
        typedef std::shared_ptr<glt::Light> light_ptr;
        /// <summary>
        /// shared_ptr a el nodo Light
        /// </summary>
        light_ptr light;

    public:

        /// <summary>
        /// Constructor del componente
        /// </summary>
        /// <param name="parent">entity padre del componente</param>
        /// <returns></returns>
        Light_Component(Entity* parent);

        /// <summary>
        /// Inicializa los parametros necesarios
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() override;

        /// <summary>
        /// Retornal el puntero al Light
        /// </summary>
        /// <returns>shared_ptr a light</returns>
        light_ptr get_Light();

        /// <summary>
        /// Parsea parametros a las variables indicadas
        /// </summary>
        /// <param name="name">parametro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        virtual bool parse_property
        (
            const string& name,
            const string& value
        ) override;

        /// <summary>
        /// Retorna el tipo del componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        string get_type_component() override;

        /// <summary>
        /// Retorna puntero al nodo que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a node</returns>
        std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Retorna puntero a node model
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<Model> get_model() override;

        /// <summary>
        /// Retorna puntero a node LIGHT
        /// </summary>
        /// <returns>shared_ptr a light</returns>
        std::shared_ptr<Light> get_light() override;

        /// <summary>
        /// Retorna puntero a node camera
        /// </summary>
        /// <returns>shared_ptr a camera</returns>
        std::shared_ptr<Camera> get_camera() override;

    };
}