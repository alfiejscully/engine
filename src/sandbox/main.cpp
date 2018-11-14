#include <iostream>
#include <memory>
#include <string>

#include "Core.h"
#include "Screen.h"

int main(int argc, char *argv[])
{
	// instance of core created 
	std::shared_ptr<Core> core(new Core());
	Screen window("Engine", 800, 600);
	

	while (!window.IsClosed())
	{
		window.PollEvents();
		
		/*core->Run();*/

	}

	

   

	return 0;
}
