#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> empty;

	for (int i=0; i!=10; ++i)
		empty.push_back(i * 2);

	std::cout << "empty: ";
	for (int i=0; i!=10; ++i)
		std::cout << empty.at(i) << ", ";
	std::cout << std::endl;
	std::cout << "easyfind(10): " << *easyfind(empty, 10) << std::endl;
	std::cout << "easyfind(11): " << *easyfind(empty, 11) << std::endl;
	return (0);
}
