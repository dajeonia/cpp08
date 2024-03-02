#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdexcept>
# include <iostream>

typedef unsigned long size_t;

class Span {
	int* arr;
	const size_t mx;
	size_t sz;
	static unsigned int span(int, int);
	static unsigned int min(unsigned int, unsigned int);
	static unsigned int max(unsigned int, unsigned int);
public:
	class NoSpanException : public std::exception {
	public:
		char const* what(void) const throw();
	};

	Span();
	Span(const Span&);
	Span(unsigned int);
	Span& operator=(const Span&);
	~Span();

	size_t size(void) const;
	int& at(unsigned int);
	const int& at(unsigned int) const;

	void addNumber(int);
	template<typename Iterator>
	void addNumber(Iterator beg, Iterator end) {
		if (static_cast<size_t>(end - beg) > mx - sz)
			throw (std::range_error("Span: 용량이 부족합니다"));
		for (; beg!=end; ++beg)
			addNumber(*beg);
	}
	unsigned int shortestSpan(void) const;
	unsigned int largestSpan(void) const;
};

std::ostream& operator<<(std::ostream& os, const Span& s);

#endif
