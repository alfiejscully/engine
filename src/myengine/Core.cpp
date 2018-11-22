#include <iostream>

#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"
#include "Keyboard.h"
#include "ShaderProgram.h"

Core::Core()
{
	// Screen created
	m_window = new Screen("ParaDox Engine", 800, 600);

	std::shared_ptr<Keyboard> m_key(new Keyboard());

	glGenBuffers(1, &vbo);

	//vertices for single triangle 
	GLfloat vertices[] = 
	{
	 0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
	};
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::shared_ptr<ShaderProgram> m_shader(new ShaderProgram("../shaders/VertShader.vert", "../shaders/FragShader.frag"));
}

Core::~Core()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

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
	while (m_running)
	{
		m_running = m_key->PollEvents();
		// call and pass core to tick
		Tick();
	}
	SDL_Quit();
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
	transform->SetLocalPosition({ 0.0f, 0.0f, 0.0f });

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

	//------------------------------------------------------------------------------

	m_shader->Draw();

	SDL_GL_SwapWindow(m_window->GetWindow());
}