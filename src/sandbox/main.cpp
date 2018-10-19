#include <iostream>
#include <memory>
#include <string>

#include "Entity.h"
#include "Component.h"
#include "TestScreen.h"

int main()
{
	std::shared_ptr<Entity> e(new Entity("fred"));

	std::shared_ptr<Component> c(new Component());
	std::shared_ptr<Component> c1(new Component());
	std::shared_ptr<Component> c2(new Component());
	std::shared_ptr<TestScreen> c3(new TestScreen());

	std::shared_ptr<Component> d;
	std::shared_ptr<Component> d1;
	std::shared_ptr<Component> d2;
	std::shared_ptr<TestScreen> d3;

	//add component to entity
	e->AddComponent(c);
	e->AddComponent(c1);
	e->AddComponent(c2);
	e->AddComponent(c3);

	// get the component from the entity
	d = e->GetComponent<Component>(0);
	d1 = e->GetComponent<Component>(1);
	d2 = e->GetComponent<Component>(2);
	d3 = e->GetComponent<TestScreen>(3);

	d->test = 10;
	d1->test = 20;
	d2->test = 30;
	d3->test = 40;
	d3->health = 50;

	std::cout << e->GetName() << std::endl;
	std::cout << std::endl;
	std::cout << d->test << std::endl;
	std::cout << d1->test << std::endl;
	std::cout << d2->test << std::endl;
	std::cout << d3->test << std::endl;
	std::cout << d3->health << std::endl;

	std::cin.get();

	return 0;

}