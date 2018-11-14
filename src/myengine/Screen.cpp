#include "Screen.h"
#include <iostream>
#include <exception>

Screen::Screen(const std::string &title, int width, int height) 
{
	m_title = title;
	m_width = width;
	m_height = height;

	if (!Init())
	{
		m_quit = true;
	}
}

Screen::~Screen()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
bool Screen::Init()
{
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

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(m_window);

	return true;
}

void Screen::PollEvents()
{
	SDL_Event event = {0};

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
	}
}