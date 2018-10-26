#include <iostream>
#include <memory>
#include <string>

#include "Core.h"

int main()
{
	// instance of core created 
	std::shared_ptr<Core> core(new Core());

	core->Run();

	std::cin.get();

	return 0;
}
