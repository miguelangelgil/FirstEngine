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
#include <Node.hpp>
#include <Component.hpp>

namespace engine
{
    using namespace glt;
    class Entity;
    class Transform_Component : public Component
    {
    private:

        /// <summary>
        /// Posición
        /// </summary>
        glm::vec3 position;

        /// <summary>
        /// rotación
        /// </summary>
        glm::vec3 rotation;

        /// <summary>
        /// Scala
        /// </summary>
        glm::vec3 scale;

        /// <summary>
        /// Indica cuanto tiene que desplazarse en un determinado fotograma
        /// </summary>
        glm::vec3 translation;

        /// <summary>
        /// Puntero a node, usamos las funcionalidades de transformaciones que nos ofrece
        /// </summary>
        std::shared_ptr<glt::Node> transform;
    public:

        /// <summary>
        /// Constructor de componente
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <param name="position">posicion inicial</param>
        /// <param name="rotation">rotacion inicial</param>
        /// <param name="scale">scala inicial</param>
        /// <returns></returns>
        Transform_Component(Entity* parent, Vector3 position, Vector3 rotation, Vector3 scale);

        /// <summary>
        /// Inicializa los parametros necesarios
        /// </summary>
        /// <returns></returns>
        bool initialize() override;

        /// <summary>
        /// Setea una posición
        /// </summary>
        /// <param name="new_position">vector3 que indica la nueva posición</param>
        void set_position(glm::vec3 new_position);

        /// <summary>
        /// Setea una nueva rotacion
        /// </summary>
        /// <param name="x">rotacion en x</param>
        /// <param name="y">rotacion en y</param>
        /// <param name="z">rotacion en z</param>
        void set_rotation(float x, float y, float z);

        /// <summary>
        /// Setea una escala
        /// </summary>
        /// <param name="x">escala en x</param>
        /// <param name="y">escala en y</param>
        /// <param name="z">escala en z</param>
        void set_scale(float x, float y, float z);

        /// <summary>
        /// Indica la translacion que hay que realizar en este fotograma
        /// </summary>
        /// <param name="new_traslate">translacion</param>
        void set_traslate(glm::vec3 new_traslate);

        /// <summary>
        /// Retorna la posicion
        /// </summary>
        /// <returns>glm::vec3 que indica la posicion</returns>
        glm::vec3* get_position();

        /// <summary>
        /// retorna la rotacion
        /// </summary>
        /// <returns>glm::vec3 que indica la rotacion</returns>
        glm::vec3* get_rotation();

        /// <summary>
        /// retorna la escala
        /// </summary>
        /// <returns>glm::vec3 que indica la escala</returns>
        glm::vec3* get_scale();

        /// <summary>
        /// Prasea parametros a las variables indicadas
        /// </summary>
        /// <param name="name">parametros</param>
        /// <param name="value">valores</param>
        /// <returns></returns>
        bool parse_property(const string& name, const string& value) override;

        /// <summary>
        /// Setea un transform 
        /// </summary>
        /// <param name="node">shared_ptr a Node</param>
        void set_Transform(std::shared_ptr<glt::Node> node);

        /// <summary>
        /// Aplica todas las trasnformaciones pendientes
        /// </summary>
        void apply_Transform();

        /// <summary>
        /// Retorna las trasnformaciones del componente
        /// </summary>
        /// <returns>glt::Matrix44 transformaciones</returns>
        glt::Matrix44 get_transformation();

        /// <summary>
        /// Retorna el tipo del componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo del componente</returns>
        string get_type_component() override
        {
            return "transform";
        }

        /// <summary>
        /// Retorna el puntero al node que contenga el componente
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        std::shared_ptr<glt::Node> get_node_component() override
        {
            return transform;
        }

        /// <summary>
        /// Retorna el puntero al node model
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<glt::Model> get_model() override
        {
            return std::shared_ptr<glt::Model>();
        }
        /// <summary>
        /// Retorna el puntero a node light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        std::shared_ptr<glt::Light> get_light() override
        {
            return std::shared_ptr<glt::Light>();
        }

        /// <summary>
        /// Retorna le puntero a node camera
        /// </summary>
        /// <returns>shared_ptr a camera</returns>
        std::shared_ptr<glt::Camera> get_camera() override
        {
            return std::shared_ptr<glt::Camera>();
        }
    };

}
