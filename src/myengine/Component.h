#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H
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
	std::shared_ptr<Entity> GetEntity();

	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<Environment> GetEnvironment();

};
#endif