#include <memory>
#include <vector>
#include <SDL2/SDL.h>

class Environment;
class Entity;
class Keyboard;
class Screen;

class Core
{
private:

	std::shared_ptr<Environment> m_environment;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::shared_ptr<Keyboard> m_keyboard;
	std::shared_ptr<Screen> m_screen;
	bool m_runninng;

	SDL_Window* m_window;

public:

	std::shared_ptr<Core> Initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> AddEntity();


};