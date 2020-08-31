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
#include <Variant.hpp>
#include <EngineTypeDef.hpp>
#include <Transform_Component.hpp>
#include <Scene.hpp>
#include <memory>

namespace engine
{
    using namespace std;

    class Component;
    class Entity
    {

        typedef std::shared_ptr<Component> component_ptr;
        /// <summary>
        /// Mapa de componentes que contiene la entidad
        /// </summary>
        std::map<string, component_ptr> components;
        /// <summary>
        /// Transform de la entidad
        /// </summary>
        component_ptr transform;
        /// <summary>
        /// Iterador de componentes
        /// </summary>
        std::map<string, component_ptr>::iterator iterator_components;
        /// <summary>
        /// puntero a la escena
        /// </summary>
        Scene* scene;
        /// <summary>
        /// nombre de la entidad
        /// </summary>
        string name;
        

    public:

        /// <summary>
        /// Constructor de la entidad
        /// </summary>
        /// <param name="name">nombre</param>
        /// <param name="scene">puntero a la escena</param>
        /// <param name="position">posicion inicial</param>
        /// <param name="rotation">rotacion inicial</param>
        /// <param name="scale">escala inicial</param>
        /// <returns></returns>
        Entity(string name,Scene* scene, Vector3 position, Vector3 rotation, Vector3 scale);

        ~Entity() = default;

        /// <summary>
        /// Inicializa la entidad
        /// </summary>
        /// <returns></returns>
        bool initialize();

        /// <summary>
        /// Anyade componenetes a la escena
        /// </summary>
        /// <param name="type">cadena de texto que indica el nombre del componentes</param>
        /// <param name="component">referencia al shared_ptr del componente</param>
        /// <returns></returns>
        bool add_component
        (
            const string& type,
            shared_ptr< Component >& component
        );
        /// <summary>
        /// Retorna un componente
        /// </summary>
        /// <param name="name_component">nombre del componente</param>
        /// <returns></returns>
        shared_ptr<Component> get_component(string name_component);

        /// <summary>
        /// Retorna el mapa de componentes
        /// </summary>
        /// <returns>std::map<string, shared_ptr<Component>></returns>
        std::map<string, component_ptr>* get_components() 
        {
            return &components;
        }
        /// <summary>
        /// Retorna el nodo que contiene el componente que se encuentre en la posicion indicada
        /// </summary>
        /// <param name="i">posicion del componente</param>
        /// <returns>std::shared_ptr<glt::Node></returns>
        std::shared_ptr<glt::Node> get_component_iterator(size_t i);

        /// <summary>
        /// Retorna el puntero a la escena
        /// </summary>
        /// <returns></returns>
        Scene* get_scene()
        {
            return scene;
        }
        /// <summary>
        /// Retorna el nombre de la entidad
        /// </summary>
        /// <returns></returns>
        string get_name() 
        {
            return name;
        }
        

    };

}