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

	//virtual void m_onInit();
	//virtual void m_onBegin();
	//virtual void m_onTick();
	//virtual void m_onDisplay();

public:
	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<Environment> GetEnvironment();

};
#endif