// Author: Miguel Ángel Gil Martín
// © Copyright (C) 2019  Miguel Ángel Gil Martín (MAGM_a)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <AudioController.hpp>
#include <SDL.h>
#include <SDL_mixer.h>

namespace engine
{
    AudioController::AudioController()
    {

        // start SDL with audio support
        if (SDL_Init(SDL_INIT_AUDIO) == -1) {
            printf("SDL_Init: %s\n", SDL_GetError());
            exit(1);
        }
        // open 44.1KHz, signed 16bit, system byte order,
        //      stereo audio, using 1024 byte chunks
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(2);
        }
    }
    AudioController::~AudioController()
    {

        Mix_CloseAudio();
        while (Mix_Init(0))
            Mix_Quit();
    }
    ///Añade una pista de musico
    ID AudioController::add_musick(const char* path)
    {
        ID id;
        if (music.empty()) { id = 0; }
        else { --music.end(); }
        music[id] = Mix_LoadMUS(path);
        return id;
    }
    ////Añade una pista de sonido
    ID AudioController::add_sound(const char* path)
    {
        ID id;
        if (sound.empty()) { id = 0; }
        else { --sound.end(); }
        sound[id] = Mix_LoadWAV(path);
        return id;
    }
    void AudioController::play_sound_track_channel(int channel, int track, int loops, int ticks)
    {
        Mix_PlayChannelTimed(channel, sound[track], loops, ticks);
    }

    void AudioController::play_music_track_channel(int track, int loops)
    {
        Mix_PlayMusic(music[track], loops);
    }
    void AudioController::channel_volume(int channel, int volume)
    {
        porcentaje->set_porcentaje(volume);
        Mix_Volume(channel, (int)porcentaje->get_porcentaje());
    }
    void AudioController::music_volume(int volume)
    {
        porcentaje->set_porcentaje(volume);
        Mix_VolumeMusic((int)porcentaje->get_porcentaje());
    }
    void AudioController::pause_channel(int channel)
    {
        Mix_Pause(channel);
    }
    void AudioController::pause_music()
    {
        Mix_PauseMusic();
    }
}