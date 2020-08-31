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
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include <Model_Obj.hpp>

namespace engine
{
    using namespace std;
    using namespace glt; 
    class Entity;
    class Model_Component : public Component
    {

        typedef glt::Model_Obj model_Obj;
        typedef std::shared_ptr<model_Obj> model_ptr;

        /// <summary>
        /// Puntero a Model 
        /// </summary>
        model_ptr model;
        /// <summary>
        /// Puntero a model con valor por defecto
        /// </summary>
        shared_ptr< glt::Model  > model1;

    public:
        /// <summary>
        /// Constructor del componente 
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <param name="path">ruta del obj a cargar</param>
        /// <returns></returns>
        Model_Component(Entity* parent, const string path);

        /// <summary>
        /// Constructor del componente
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <returns></returns>
        Model_Component(Entity* parent);

        /// <summary>
        /// Inicializa los parametros necesarios
        /// </summary>
        /// <returns></returns>
        bool initialize() override;

        /// <summary>
        /// Parsea parametros en las variables indicadas
        /// </summary>
        /// <param name="name">parametro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        bool parse_property(const string& name, const string& value) override
        {
            return false;
        }
      
        /// <summary>
        /// Retorna el tipo del componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        string get_type_component() override
        {
            return "model";
        }

        /// <summary>
        /// Retorna el puntero al nodo que contiene el componente
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Retorna el puntero al nodo Model
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<Model> get_model() override;

        /// <summary>
        /// Retorna puntero al nodo Light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        std::shared_ptr<Light> get_light() override;

        /// <summary>
        /// Retornal el puntero al nodo Camera
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        std::shared_ptr<Camera> get_camera() override;


    };
} 