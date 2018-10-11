#include <vector>
#include <memory>
#include <string>

class Component;
class Core;

class Entity
{
private:

	std::vector<std::shared_ptr<Component>> m_components;
	std::weak_ptr<Core> m_core;

public:

	// --- constructor in this file 

	std::shared_ptr<Core> getCore();

	//--- templates needed here to add components

	void tick();
	void display();


};