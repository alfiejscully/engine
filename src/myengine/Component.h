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

	/*void m_onInit();
	void m_onBegin();
	void m_onTick();
	void m_onDisplay();*/

public:

	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<Environment> GetEnvironment();

};
#endif