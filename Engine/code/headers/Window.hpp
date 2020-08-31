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
#include <string>
#include <cassert>
#include <SDL.h>


namespace engine
{

	class Window
	{
	public:

		enum Fullscreen_Type
		{
			REAL = SDL_WINDOW_FULLSCREEN,
			DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP
		};

	private:

		SDL_Window* window;
		SDL_GLContext gl_context;
		SDL_Event *event = new SDL_Event();

	public:
		/**
		Constructor de clase, crea una ventana
		title titulo de la ventana
		width ancho de la ventana
		height alto de la ventana
		fullscreen, si es true la ventana ocupa toda la pantalla
		*/
		Window(const std::string& title, int width, int height, bool fullscreen = false);

		/**
		Destructor de clase
		*/
		~Window();
		/**
		Coloca la pantalla completa por defecto
		type, por defecto pantalla completa
		*/
		void set_fullscreen(Fullscreen_Type type = Fullscreen_Type::DESKTOP);
		/**
		Recoloca la ventana en unas nueevas corrdenadas
		new_left_x indica la coordenada x de la esquina superior izquierda de la ventana
		new_top_y indica la coordenada y de la esquina superior izquierda de la ventana
		*/
		void set_position(int new_left_x, int new_top_y);
		/**
		Redimensiona la ventana actual
		new_width nueva dimensiones de ancho
		new_height nuevas dimensiones de alto
		*/
		void set_size(int new_width, int new_height);

		void set_relative_mouse(bool value);

		SDL_WindowEventID PrintEvent();

		unsigned get_width() const;

		unsigned get_height() const;

		void clear() const;

		void swap_buffers() const;
	};

}