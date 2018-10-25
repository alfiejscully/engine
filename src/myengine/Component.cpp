#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Keyboard.h"
#include "Environment.h"



std::shared_ptr<Entity> Component::GetEntity()
{
	return std::shared_ptr<Entity>();
}

std::shared_ptr<Core> Component::GetCore()
{
	return std::shared_ptr<Core>();
}

std::shared_ptr<Keyboard> Component::GetKeyboard()
{
	return std::shared_ptr<Keyboard>();
}

std::shared_ptr<Environment> Component::GetEnvironment()
{
	return std::shared_ptr<Environment>();
}
