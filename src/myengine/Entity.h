#include <vector>
#include <memory>
#include <string>

class Component;
class Core;
class TestScreen;

class Entity
{
private:
	std::vector<std::shared_ptr<Component>> m_components;
	std::weak_ptr<Core> m_core;
	std::string m_name;

	void m_tick();
	void m_display();
	

public:
	Entity(std::string _name);
	std::string GetName() { return m_name; }

	/*void SetName(std::string name) { m_name = name; }*/

	void AddComponent(std::shared_ptr<Component> _component);

	// Used to get the component without knowing the specific type (is it a TestScreen? is it a Rigidbody?
	// Who knows, who cares!!)
	template <typename T> std::shared_ptr<T> GetComponent(int _i)
	{
		return std::static_pointer_cast<T>(m_components.at(_i));
	}

	std::shared_ptr<Core> GetCore();


};