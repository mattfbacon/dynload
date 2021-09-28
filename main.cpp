#include <iostream>
#include <dlfcn.h>

#include "LibData.hpp"

void load_and_run_lib() {
	void* lib = dlopen("./lib.so", RTLD_LAZY);
	if (char const* err = dlerror(); err) {
		std::cerr << err << std::endl;
		exit(EXIT_FAILURE);
	}
	LibData* lib_data = (LibData*)dlsym(lib, "lib_data");
	if (char const* err = dlerror(); err) {
		std::cerr << err << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Name: " << lib_data->name << std::endl;
	lib_data->fn();
	dlclose(lib);
}

int main() {
	load_and_run_lib();
	std::cerr << "Make a change to the library, recompile it, and press Enter to see hot-reloading in action!" << std::flush;
	getchar();
	load_and_run_lib();
	return EXIT_SUCCESS;
}
