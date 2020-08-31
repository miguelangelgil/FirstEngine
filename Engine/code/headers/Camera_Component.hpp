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
#include <Camera.hpp>
#include <Component.hpp>

namespace engine 
{
    class Entity;
    class Camera_Component : public Component
    {
    private:
       
        typedef std::shared_ptr<glt::Camera>  camera_ptr;
        /// <summary>
        /// guarda un puntero a la camara de node
        /// </summary>
        camera_ptr camera;
    public:
        /// <summary>
        /// Constructor del componente
        /// </summary>
        /// <param name="parent">el padre del componente</param>
        /// <returns></returns>
        Camera_Component(Entity* parent);

        /// <summary>
        /// Inicializa los parámetros necesários del componente
        /// </summary>
        /// <returns></returns>
        bool initialize() override;

        /// <summary>
        /// Parsea los valores recividos a las variables que se le indiquen
        /// </summary>
        /// <param name="name">parámetro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        bool parse_property(const string& name, const string& value) override;

        /// <summary>
        /// Devuelve el tipo de componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente que es</returns>
        string get_type_component() override;

        /// <summary>
        /// Retorna el puntero al nodo que tenga
        /// </summary>
        /// <returns>shared_ptr a node</returns>
        std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Direccióna la camara para que apunte a un punto en el espacio
        /// </summary>
        /// <param name="where">coordenadas donde quieres que mire la camara</param>
        void look_at(const glt::Vector3& where);

        /// <summary>
        /// Retorna puntero al modelo que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<glt::Model> get_model() override;

        /// <summary>
        /// Retorna puntero a la luz que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a  Light</returns>
        std::shared_ptr<glt::Light> get_light() override;

        /// <summary>
        /// Retorna puntero a la camara que contenga el componente 
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        std::shared_ptr<glt::Camera> get_camera() override;

    };
}
