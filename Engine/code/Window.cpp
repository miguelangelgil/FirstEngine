#pragma once
#include <Window.hpp>
#include <SDL.h>
#include <OpenGL.hpp>
#include <Initialize.hpp>

using namespace engine;
namespace engine
{
	Window::Window(const std::string& title, int width, int height, bool fullscreen)
	{
		window = nullptr;
		gl_context = nullptr;

		if (initialize(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			assert(window != nullptr);

			if (window)
			{
				gl_context = SDL_GL_CreateContext(window);

				assert(gl_context != nullptr);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					if (fullscreen)
					{
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
			}
		}

	}
	/**
	Destructor de clase
	*/
	Window::~Window()
	{
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		if (window) SDL_DestroyWindow(window);
	}
	/**
	Coloca la pantalla completa por defecto
	type, por defecto pantalla completa
	*/
	void Window::set_fullscreen(Fullscreen_Type type)
	{
		SDL_SetWindowFullscreen(window, type);
	}
	/**
	Recoloca la ventana en unas nueevas corrdenadas
	new_left_x indica la coordenada x de la esquina superior izquierda de la ventana
	new_top_y indica la coordenada y de la esquina superior izquierda de la ventana
	*/
	void Window::set_position(int new_left_x, int new_top_y)
	{
		SDL_SetWindowPosition(window, new_left_x, new_top_y);
	}
	/**
	Redimensiona la ventana actual
	new_width nueva dimensiones de ancho
	new_height nuevas dimensiones de alto
	*/
	void Window::set_size(int new_width, int new_height)
	{
		SDL_SetWindowSize(window, new_width, new_height);

	}

	void Window::set_relative_mouse(bool value)
	{
		SDL_SetRelativeMouseMode((SDL_bool)value);
	}

	unsigned Window::get_width() const
	{
		int width = 0, height;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(width);
	}

	unsigned Window::get_height() const
	{
		int width, height = 0;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(height);
	}
	void Window::clear() const
	{
		if (gl_context) {
			glClearColor(0.4f, 0.4f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}
	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(window);
	}

	/**
	Controla los eventos de la ventana y devuleve el evento
	*/
	SDL_WindowEventID  Window::PrintEvent()
	{
		while (SDL_PollEvent(event) != 0)
		{
			if (event->type == SDL_WINDOWEVENT) {
				switch (event->window.event) {
				case SDL_WINDOWEVENT_SHOWN:
					SDL_Log("Window %d shown", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					SDL_Log("Window %d hidden", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_EXPOSED:
					SDL_Log("Window %d exposed", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MOVED:
					SDL_Log("Window %d moved to %d,%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
					break;
				case SDL_WINDOWEVENT_RESIZED:
					SDL_Log("Window %d resized to %dx%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					SDL_Log("Window %d size changed to %dx%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					SDL_Log("Window %d minimized", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					SDL_Log("Window %d maximized", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_RESTORED:
					SDL_Log("Window %d restored", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_ENTER:
					SDL_Log("Mouse entered window %d",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_LEAVE:
					SDL_Log("Mouse left window %d", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					SDL_Log("Window %d gained keyboard focus",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					SDL_Log("Window %d lost keyboard focus",
						event->window.windowID);
					break;
				case SDL_WINDOWEVENT_CLOSE:
					SDL_Log("Window %d closed", event->window.windowID);
					break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
				case SDL_WINDOWEVENT_TAKE_FOCUS:
					SDL_Log("Window %d is offered a focus", event->window.windowID);
					break;
				case SDL_WINDOWEVENT_HIT_TEST:
					SDL_Log("Window %d has a special hit test", event->window.windowID);
					break;
#endif
				default:
					SDL_Log("Window %d got unknown event %d",
						event->window.windowID, event->window.event);
					break;
				}
			}
			return SDL_WindowEventID(event->window.event);
		}
		return SDL_WindowEventID(event->window.event);

	}
}