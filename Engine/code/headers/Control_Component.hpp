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
    class Control_Component : public Component
    {
    public:
        string Up; ///< Letra que maneja la accion
        string Down; ///< Letra que maneja la accion
        string Left; ///< Letra que maneja la accion
        string Right; ///< Letra que maneja la accion
        string Jump; ///< Letra que maneja la accion
        float  speed; ///< Velocidad de movimiento
        float  JumpForce; ///< Velocidad de movimiento

    public:
        /// <summary>
        /// Constructor de clase
        /// </summary>
        /// <param name="entity">Entidad padre que posee el componente</param>
        /// <returns></returns>
        Control_Component(Entity * entity);
        // Heredado vía Component

        /// <summary>
        /// Inicializa los parámetros necesarios del componente
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
        /// Retorna puntero al node que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        virtual std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Retornal puntero al node model
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        virtual std::shared_ptr<glt::Model> get_model() override;

        /// <summary>
        /// Retorna puntero al node light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        virtual std::shared_ptr<glt::Light> get_light() override;
        /// <summary>
        /// Retornal puntero al node camera
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        virtual std::shared_ptr<glt::Camera> get_camera() override;
    };

}
