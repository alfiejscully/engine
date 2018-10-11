#include <memory>
#include <vector>

class Environment;
class Entity;
class Keyboard;

class Core
{
private:

	std::shared_ptr<Environment> m_environment;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::shared_ptr<Keyboard> m_keyboard;
	bool m_runninng;

public:

	std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();


};