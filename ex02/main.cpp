#include <iostream>
#include "MutantStack.hpp"

/*
int	main(void)
{
	MutantStack a;

	return (0);
}
*/

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(9);

	const MutantStack<int> mstack2(mstack);
	mstack.push(737);

	MutantStack<int> mstack3;
	mstack3 = mstack;
	mstack.push(0);

	std::cout << "= mstack ================" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "= mstack2 ===============" << std::endl;
	MutantStack<int>::const_iterator it2 = mstack2.begin();
	MutantStack<int>::const_iterator ite2 = mstack2.end();
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "= mstack3 ===============" << std::endl;
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	while (it3 != ite3) {
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::cout << "= mstack(r) =============" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << "= mstack2(r) =============" << std::endl;
	MutantStack<int>::const_reverse_iterator rit2 = mstack2.rbegin();
	MutantStack<int>::const_reverse_iterator rite2 = mstack2.rend();
	while (rit2 != rite2) {
		std::cout << *rit2 << std::endl;
		++rit2;
	}
	std::cout << "=========================" << std::endl;
	return 0;
}
