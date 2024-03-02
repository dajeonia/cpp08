#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> empty;

	for (int i=0; i!=10; ++i)
		empty.push_back(i * 2);
	for (int i=0; i!=10; ++i)
		std::cout << empty.at(i) << std::endl;
	std::cout << "easyfind(10): " << *easyfind(empty, 10) << std::endl;
	std::cout << "easyfind(11): " << *easyfind(empty, 11) << std::endl;
	std::cout << "find(10): " << *find(empty.begin(), empty.end(), 10) << std::endl;
	std::cout << "find(11): " << *find(empty.begin(), empty.end(), 11) << std::endl;
	return (0);
}
