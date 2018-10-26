#include <iostream>

#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"

std::shared_ptr<Entity> Core::AddEntity(std::string _name)
{
	// instance of entity created 
	std::shared_ptr<Entity> entity(new Entity(_name));

	m_entities.push_back(entity);

	return entity;
}

std::shared_ptr<Entity> Core::GetEntity(int _entity)
{
	return m_entities.at(_entity);
}

void Core::Run()
{
	// call and pass core to init
	Init();

	// game loop
	while (true)
	{
		// call and pass core to tick
		Tick();
	}
}

void Core::Init()
{

	// Entity created and added to scene
	std::shared_ptr<Entity> e = AddEntity("fred");


	// instance of transform created 
	std::shared_ptr<Transform> transform(new Transform());

	//add the transform component to entity
	e->AddComponent(transform);

	// set the position of entity
	transform->SetLocalPosition({ 10.0f, 0.0f, 0.0f });

	// output the name once into program
	std::cout << e->GetName() << std::endl;
}

void Core::Tick()
{
	// get entity at first index in core
	std::shared_ptr<Entity> e = GetEntity(0);

	// get the transform component 
	std::shared_ptr<Transform> transform = e->GetComponent<Transform>(0);

	// translates the entity by one each tick on the x axis
	transform->Translate({ 1.0f, 0.0f, 0.0f });

	// print out x position
	std::cout << transform->GetLocalPosition().x << std::endl;
}