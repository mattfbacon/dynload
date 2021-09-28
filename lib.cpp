#include <iostream>

#include "LibData.hpp"

static void lib() {
	std::cout << "Hello from lib" << std::endl;
}

extern "C" {
	LibData lib_data{
		.name = "Library after Hot-Reloading",
		.fn = &lib
	};
}
