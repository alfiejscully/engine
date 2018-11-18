#include <iostream>
#include <memory>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Core.h"
#include "Screen.h"
#include "Keyboard.h"
#include "ShaderProgram.h"


int main(int argc, char *argv[])
{

	// instance of core created 
	std::shared_ptr<Core> core(new Core());
	Screen window("Engine", 800, 600);
	std::shared_ptr<Keyboard> quit(new Keyboard());
	std::shared_ptr<ShaderProgram> shader(new ShaderProgram("../shaders/VertShader.vert", "../shaders/FragShader.frag"));
	
	
	

	float vertices[] = {
	 0.0f,  0.5f, // Vertex 1 (X, Y)
	 0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!quit->IsClosed())
	{
		quit->PollEvents();
		
		/*core->Run();*/
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->Draw();


		SDL_GL_SwapWindow(window.GetWindow());
	}

	

	//glDeleteBuffers(1, &ebo);
	//glDeleteBuffers(1, &vbo);

	//glDeleteVertexArrays(1, &vao);

	return 0;
}
