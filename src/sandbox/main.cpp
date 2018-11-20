#include <iostream>
#include <memory>
#include <string>
#include <GL/glew.h>

#include "Core.h"
#include "Screen.h"
#include "Keyboard.h"
#include "ShaderProgram.h"


int main(int argc, char *argv[])
{

	// Screen created
	std::shared_ptr<Screen> m_window(new Screen("Engine", 800, 600));
	// instance of core created 
	std::shared_ptr<Core> core(new Core());
	
	std::shared_ptr<Keyboard> quit(new Keyboard());
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);

	//vertices for single triangle 
	GLfloat vertices[] = {
	 0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
	};

	////vertices for rectangle 
	//GLfloat vertices[] = {
	//	-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
	//	 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
	//	 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
	//	-0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
	//};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/*GLuint ebo;
	glGenBuffers(1, &ebo);

	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0 
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);*/


	std::shared_ptr<ShaderProgram> shader(new ShaderProgram("../shaders/VertShader.vert", "../shaders/FragShader.frag"));

	while (!quit->IsClosed())
	{
		quit->PollEvents();
		
		/*core->Run();*/

		shader->Draw();

		SDL_GL_SwapWindow(m_window->GetWindow());
	}

	
	//glDeleteBuffers(1, &ebo);

	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);

	return 0;
}
