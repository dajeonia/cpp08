#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator	easyfind(T& a, int n)
{
	typename T::iterator iter(a.begin());
	for (; iter!=a.end(); ++iter) {
		if (*iter == n)
			break ;
	}
	return (iter);
}

#endif
