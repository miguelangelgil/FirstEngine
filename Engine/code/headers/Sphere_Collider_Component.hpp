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

    enum COLLISION_STATE{
        OUT_COLLISION = 0,
        ON_COLLISION_ENTER = 1,
        ON_COLLISION = 2,
        ON_COLLISION_EXIT = 3
    };


    class Entity;
    class Sphere_Collider_Component : public Component 
    {
    private:
        /// <summary>
        /// Estado de colision
        /// </summary>
        COLLISION_STATE collision_state;
    public:
        /// <summary>
        /// Radio de la sphera que compone el collider
        /// </summary>
        float radius;
    public:
        /// <summary>
        /// Constructor del componente
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <param name="radius">radio de la esfera del collider</param>
        /// <returns></returns>
        Sphere_Collider_Component(Entity * parent, float radius);
        // Heredado vía Component

        /// <summary>
        /// Inicializa todos los parametros necesarios
        /// </summary>
        /// <returns></returns>
        virtual bool initialize() override;

        /// <summary>
        /// Parsea parametros en las variables indicadas
        /// </summary>
        /// <param name="name">parametro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        virtual bool parse_property(const string& name, const string& value) override;

        /// <summary>
        /// Retorna el tipo del componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        virtual string get_type_component() override;

        /// <summary>
        /// Retornal el puntero al Node que contiene
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        virtual std::shared_ptr<glt::Node> get_node_component() override;

        /// <summary>
        /// Retornale el puntero al node model
        /// </summary>
        /// <returns>shared_ptr Model</returns>
        virtual std::shared_ptr<glt::Model> get_model() override;

        /// <summary>
        /// Retorna el puntero al node light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        virtual std::shared_ptr<glt::Light> get_light() override;
        /// <summary>
        /// Retorna el puntero al node Camera
        /// </summary>
        /// <returns>shared_ptr a camera</returns>
        virtual std::shared_ptr<glt::Camera> get_camera() override;
        /// <summary>
        /// Setea el estado de la colision
        /// </summary>
        /// <param name="state">estado</param>
        inline void set_state_collision(COLLISION_STATE state) { collision_state = state; }
        /// <summary>
        /// devuelve el estado de la colision
        /// </summary>
        /// <returns>estado</returns>
        inline COLLISION_STATE get_state_collision() const { return collision_state; }

        string get_type_collider();
    };
}