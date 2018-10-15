#include "Entity.h"
#include "Core.h"

//constructor 

Entity::Entity(std::string _name)
{
	_name = m_name;
}

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