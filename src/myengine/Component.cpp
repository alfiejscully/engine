#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Keyboard.h"
#include "Environment.h"

std::shared_ptr<Entity> Component::getEntity()
{
	return std::shared_ptr<Entity>();
}

std::shared_ptr<Core> Component::getCore()
{
	return std::shared_ptr<Core>();
}

std::shared_ptr<Keyboard> Component::getKeyboard()
{
	return std::shared_ptr<Keyboard>();
}

std::shared_ptr<Environment> Component::getEnvironment()
{
	/*return std::shared_ptr<Environment>();*/
}