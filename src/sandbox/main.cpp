#include <iostream>
#include <memory>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Core.h"
#include "Screen.h"
#include "Keyboard.h"


int main(int argc, char *argv[])
{
	// instance of core created 
	std::shared_ptr<Core> core(new Core());
	std::shared_ptr<Keyboard> quit(new Keyboard());
	Screen window("Engine", 800, 600);
	
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window.GetWindow());

	while (!quit->IsClosed())
	{
		quit->PollEvents();
		
		/*core->Run();*/

	}

	

   

	return 0;
}
