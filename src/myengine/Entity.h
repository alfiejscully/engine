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
	std::string m_name;

	void m_tick();
	void m_display();
	//int x;

public:

	// --- constructor in this file 
	Entity(std::string _name);
	std::string GetName() { return m_name; }

	//int GetX() { return x; }
	//void SetX(int _x) { x = _x; }

	std::shared_ptr<Core> getCore();

	//--- templates needed here to add components


};