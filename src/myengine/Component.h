#include <memory>

class Entity;
class Core;
class Keyboard;
class Environment;

class Component
{
private:

	std::weak_ptr<Entity> m_entity;


public:

	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();

};