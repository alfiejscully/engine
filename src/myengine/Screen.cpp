#include "Screen.h"
#include <iostream>
#include <exception>

Screen::Screen(const std::string &title, int width, int height) 
{
	m_title = title;
	m_width = width;
	m_height = height;

	Init();
}

Screen::~Screen()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Screen::Init()
{
	//SDL_Init(SDL_INIT_EVERYTHING);

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Failed to initalize SDL.\n";
		return 0;
	}

	m_window = SDL_CreateWindow(m_title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		m_width, m_height,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(m_window))
	{
		throw std::exception();
	}
	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	if (!m_window)
	{
		std::cout << "Window failed to create" << std::endl;
		SDL_Quit();
	}

	return true;
}

SDL_Window* Screen::GetWindow()
{
	return m_window;
}
