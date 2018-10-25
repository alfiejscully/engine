#include "Core.h"
#include "Entity.h"
#include "Screen.h"

std::shared_ptr<Core> Core::Initialize()
{
	return std::shared_ptr<Core>();
}

void Core::Start()
{
	
}

void Core::Stop()
{

}

void Core::AddEntity(std::shared_ptr<Entity> _entity)
{
	m_entities.push_back(_entity);
}

