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
#include <Math.hpp>
#include <Transform_Component.hpp>
#include <Observer.hpp>
using namespace std;
using namespace glt;
namespace engine
{
    class Input;
    class Entity;
    class Input_Component : public Component , public Observer
    {

    public:
        /// <summary>
        /// Puntero a la clase Input, que lleva
        /// los eventos del teclado
        /// </summary>
        shared_ptr<Input> keyboard;

        /// <summary>
        /// Entidad padre del componente
        /// </summary>
        /// <param name="parent">entity padre</param>
        /// <returns></returns>
        Input_Component(Entity* parent);

        /// <summary>
        /// Inicializa los parametros necesarios del componente
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() override;

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
        /// Recive mensages referente al evento al que se ha suscrito
        /// </summary>
        /// <param name="message">message que contiene los eventos del teclado</param>
        void handle(const Message& message) override;

        /// <summary>
        /// Devuelve el tipo de componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        string get_type_component() override;

        /// <summary>
        /// Retorna el puntero al nodo que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        std::shared_ptr<glt::Node> get_node_component() override;
        /// <summary>
        /// Retorna el puntero al nodo Model
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<Model> get_model() override;
        /// <summary>
        /// Retornal el puntero al nodo Light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        std::shared_ptr<Light> get_light() override;
        /// <summary>
        /// Retornal el puntero al nodo camera
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        std::shared_ptr<Camera> get_camera() override;

    };
}
