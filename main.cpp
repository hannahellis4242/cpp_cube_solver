#include <iostream>

#include <sstream>
#include <optional>

#include "Configuration.h"

int main()
{
	std::cout << cube::show_net(cube::top_twist_right(cube::solved())) << std::endl ;
	return 0 ;
}
