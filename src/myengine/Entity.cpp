#include "Entity.h"
#include "Core.h"

#include "sandbox/TestScreen.h"

//constructor 

Entity::Entity(std::string _name)
{
	m_name = _name;
}

void Entity::AddComponent(std::shared_ptr<Component> _component)
{
	m_components.push_back(_component);
}

//void Entity::AddComponent(std::shared_ptr<TestScreen> _component)
//{
//	m_components.push_back(_component);
//}


std::shared_ptr<Core> Entity::GetCore()
{
	return std::shared_ptr<Core>();
}

void Entity::m_tick()
{

}

void Entity::m_display()
{

}
