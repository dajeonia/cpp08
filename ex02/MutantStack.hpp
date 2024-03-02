#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() { }
	MutantStack(const MutantStack& m) { *this = m; }
	MutantStack& operator=(const MutantStack& m)
	{
		std::stack<T>::operator=(m);
		return (*this);
	}
	~MutantStack() { }

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void) { return (std::stack<T>::c.begin()); }
	iterator end(void) { return (std::stack<T>::c.end()); }

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
	reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
};
