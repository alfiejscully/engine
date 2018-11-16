#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Screen
{
private:

	std::string m_title;
	int m_width;
	int m_height;

	SDL_Window *m_window = nullptr;

	bool Init();

public:
	Screen(const std::string &title, int width, int height);
	~Screen();

	SDL_Window* GetWindow();
	
};