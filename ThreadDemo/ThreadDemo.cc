#include <hw/inout.h>
#include <sys/neutrino.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

void  foo()
{
	std::cout << "Hello Thread Demo !" << std::endl;
}


int main(int argc, char *argv[])
{

	// Da wir IO nutzen wollen, müssen wir erstmal zugriff Berechtigung auf
	// dem Hardware bekommen.
	if (ThreadCtl(_NTO_TCTL_IO_PRIV, 0) == -1)
	{
		std::cout << "Can't get Hardware access, therefore can't do anything."
				<< std::endl;
		return EXIT_FAILURE;
	}

	// erzeugt ein Thread und führt foo() aus
	std::thread thd(foo);

	std::cout << "Thread Demo ... done !" << std::endl;
	return EXIT_SUCCESS;
}

