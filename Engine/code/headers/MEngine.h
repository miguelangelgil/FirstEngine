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
#define SDL_MAIN_HANDLED
#include<EngineTypeDef.hpp>
#include<Window.hpp>
#include<AudioController.hpp>
#include<Scene.hpp>
#include<Kernel.hpp>
#include <Cube.hpp>
#include <memory>
#include<Material.hpp>
#include <Node.hpp>
#include <Light_Component.hpp>
#include <Camera_Component.hpp>
#include <Input_Component.hpp>
#include <Transform_Component.hpp>
#include <Entities_In_Game_Update.hpp>
#include <Control_Component.hpp>
#include <IA_Component.hpp>
#include <Sphere_Collider_Component.hpp>
#include <Sound_Component.hpp>
#include <Script_Component.hpp>
#undef main
typedef shared_ptr <Component> component;
