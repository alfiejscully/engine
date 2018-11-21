#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class Screen
{
private:

	std::string m_title;
	int m_width;
	int m_height;
	glm::vec4 m_screenColour;

	SDL_Window *m_window;

	bool Init();

public:
	Screen(const std::string &title, int width, int height);
	~Screen();

	SDL_Window* GetWindow();
	
};