#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdexcept>
# include <iostream>

typedef unsigned long size_t;

class Span {
	int* arr;
	size_t mx;
	size_t sz;
	static unsigned int span(int, int);
	static unsigned int min(unsigned int, unsigned int);
	static unsigned int max(unsigned int, unsigned int);
public:
	class NoSpanException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	Span(unsigned int);
	Span& operator=(const Span&);
	~Span();

	size_t size(void) const;
	int& at(unsigned int);
	const int& at(unsigned int) const;

	void addNumber(int);
	unsigned int shortestSpan(void) const;
	unsigned int largestSpan(void) const;
private:
	Span();
	Span(const Span&);
};

std::ostream& operator<<(std::ostream& os, const Span& s);

#endif
