#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator	easyfind(T& a, int n)
{
	return (find(a.begin(), a.end(), n));
}

#endif
