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
#include <AudioController.hpp>
#include <Render_Node.hpp>
#include <Node.hpp>
namespace engine
{

    class Sound_Component : public Component
    {
    private:
        typedef uint16_t ID;
        /// <summary>
        /// id de la pista
        /// </summary>
        ID id;
        /// <summary>
        /// puntero al audio controller
        /// </summary>
        shared_ptr<AudioController> audio_controller;

    public:

        /// <summary>
        /// Constructor del componente
        /// </summary>
        /// <param name="parent">entidad padre del componente</param>
        /// <param name="path">ruta de la pista de musica o audio</param>
        /// <returns></returns>
        Sound_Component(Entity* parent, string path) : Component(parent), audio_controller(new AudioController())
        {  
            id = audio_controller->add_musick(path.c_str());
            
        }

        /// <summary>
        /// Inicializa los parametros necesarios
        /// </summary>
        /// <returns></returns>
        bool initialize() override
        {
            return true;
        }

        /// <summary>
        /// Parsea parametros a las variables indicadas
        /// </summary>
        /// <param name="name">parametro</param>
        /// <param name="value">valor</param>
        /// <returns></returns>
        bool parse_property(const string& name, const string& value) override
        {
            return false;
        }

        /// <summary>
        /// Retorna el tipo de componente
        /// </summary>
        /// <returns>cadena de texto que indica el tipo de componente</returns>
        string get_type_component() override
        {
            return "sound";
        }

        /// <summary>
        /// Inicia la reproducción de una pista
        /// </summary>
        /// <param name="volumen">volumen de reproducción, de 0 a 100</param>
        /// <param name="chanel">canal</param>
        void play(int volumen, int chanel) 
        {
            audio_controller->play_music_track_channel(id, chanel);
            audio_controller->music_volume(volumen);
        }

        /// <summary>
        /// Pausa todas las pista en reproducción
        /// </summary>
        void stop() 
        {
            audio_controller->pause_music();
        }

        /// <summary>
        /// Retorna el puntero al nodo que contenga
        /// </summary>
        /// <returns>shared_ptr a Node</returns>
        std::shared_ptr<glt::Node> get_node_component() override
        {
            return std::shared_ptr<glt::Node>();
        }

        /// <summary>
        /// Retorna el puntero al node Model 
        /// </summary>
        /// <returns>shared_ptr a Model</returns>
        std::shared_ptr<glt::Model> get_model() override
        {
            return std::shared_ptr<glt::Model>();
        }

        /// <summary>
        /// Retornal el puntero al node Light
        /// </summary>
        /// <returns>shared_ptr a Light</returns>
        std::shared_ptr<glt::Light> get_light() override
        {
            return std::shared_ptr<glt::Light>();
        }

        /// <summary>
        /// Retorna el puntero al node Camera
        /// </summary>
        /// <returns>shared_ptr a Camera</returns>
        std::shared_ptr<glt::Camera> get_camera() override
        {
            return std::shared_ptr<glt::Camera>();
        }
    };

}