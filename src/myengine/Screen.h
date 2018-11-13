#include <SDL2/SDL.h>
#include <GL\glew.h>
#include <string>

class Screen
{
private:

	std::string title;
	int width = 800;
	int height = 600;

	bool closed = false;

	SDL_Window *window = nullptr;

public:
	Screen(const std::string &title, int width, int height);
	~Screen();

};