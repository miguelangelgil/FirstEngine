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
#include <vector>
#include <Porcentaje.hpp>
#include <EngineTypeDef.hpp>
#include <SDL_mixer.h>


using namespace std;
using namespace engine;

namespace engine
{
    class AudioController
    {
    private:
        map<ID, Mix_Music* > music;
        map<ID, Mix_Chunk* > sound;

    public:
        Porcentaje* porcentaje = new Porcentaje(0, MIX_MAX_VOLUME, 100);
    public:
        /**
        Constructor por defecto
        */
        AudioController();
        /**
        Destructor
        */
        ~AudioController();
        /**
        Añade una pista de musica
        */
        ID add_musick(const char* path);
        /**
        Añade una pista de sonido
        */
        ID add_sound(const char* path);
        /**
        Empieza a reproducir un sonido en un canal
        channel canal, canal en el que quieres reproducir el sonido
        track pista, la id de la pista que quieres reproducir
        loops veces que quieres que se repita el sonido
        ticks
        */
        void play_sound_track_channel(int channel, int track, int loops, int ticks);
        /**
        Empieza a reproducir una pista de musica en un canal
        track pista, la id de la pista que quieres reproducir
        loops veces que quieres que se repita el sonido
        */
        void play_music_track_channel(int track = 0, int loops = 1);
        /**
        Modifica el volumen de un canal en concreto
        */
        void channel_volume(int channel, int volume);
        /**
        * Ajusta el volumen del audio
        */
        void music_volume(int volume);
        /**
        Pausa un canal
        */
        void pause_channel(int channel);
        /**
        Pausa la musica
        */
        void pause_music();

    };
}