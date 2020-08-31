#include "Input.hpp"
#include <SDL.h>
namespace engine {
    bool Input::is_key_pressed(string key)
    {
        return std::find(key_pressed.begin(), key_pressed.end(), key) != key_pressed.end();
    }
    void Input::set_key_down(string key)
    {
        if (std::find(key_pressed.begin(), key_pressed.end(), key) == key_pressed.end())
            key_pressed.push_back(key);
    }
    void Input::set_key_up(string key)
    {
        if (std::find(key_pressed.begin(), key_pressed.end(), key) != key_pressed.end())
            key_pressed.remove(key);
    }
}