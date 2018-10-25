#include <iostream>
#include <memory>
#include <string>

#include "Entity.h"
#include "Component.h"
//#include "TestScreen.h"
#include "Transform.h"

/*
create core in init()

then add entity to the core in init()

get entity in tick()

remove globe variable entity

*/

void Init();

void Tick();

std::shared_ptr<Entity> entity;

int main()
{
	Init();

	while (true)
	{
		Tick();
	}

	std::cin.get();

	return 0;

}

void Init()
{
	std::shared_ptr<Entity> e(new Entity("fred"));

	std::shared_ptr<Transform> transform(new Transform());

	//add component to entity
	e->AddComponent(transform);

	entity = e;

	transform->SetLocalPosition({ 10.0f, 0.0f, 0.0f });

	std::cout << e->GetName() << std::endl;
}

void Tick()
{
	std::shared_ptr<Entity> e = entity;

	std::shared_ptr<Transform> transform;

	// get the component from the entity
	transform = e->GetComponent<Transform>(0);

	transform->Translate({ 1.0f, 0.0f, 0.0f });

	std::cout << std::endl;
	std::cout << transform->GetLocalPosition().x << std::endl;
}