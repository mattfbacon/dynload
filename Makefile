OUR_CXXFLAGS := -Wall -Wextra -Werror -std=c++20

all: main lib.so
main: main.cpp LibData.hpp
	$(CXX) $(CXXFLAGS) $(OUR_CXXFLAGS) $< -o $@ -ldl
lib.so: lib.cpp LibData.hpp
	$(CXX) $(CXXFLAGS) $(OUR_CXXFLAGS) $< -o $@ -shared -fPIC
