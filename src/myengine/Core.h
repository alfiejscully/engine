#include <memory>
#include <vector>
#include <string>
#include <GL/glew.h>
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
	bool m_runninng;

	std::shared_ptr<Screen> m_window;

public:
	Core();
	~Core();

	std::shared_ptr<Entity> AddEntity(std::string _name);
	std::shared_ptr<Entity> GetEntity(int _entity);

	void Run();

	void Init();
	void Tick();
};