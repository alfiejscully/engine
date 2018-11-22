#include <memory>
#include "Core.h"

int main(int argc, char *argv[])
{
	// instance of core created 
	std::shared_ptr<Core> core(new Core());

	//calling function from class
	core->Run();

	return 0;
}
