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
	//void AddEntity(std::shared_ptr<Entity> _entity);
	std::shared_ptr<Entity> AddEntity(std::string _name);

	std::shared_ptr<Entity> GetEntity(int _entity);

	void Run();

	void Init();
	void Tick();
};