#include "Span.hpp"

char const*	Span::NoSpanException::what(void) const throw() { return ("No span can be found"); }

Span::Span(void) : arr(new int[0]), mx(0), sz(0) { }

Span::Span(unsigned int N) : arr(new int[N]), mx(N), sz(0) { }

Span::Span(const Span& s) : arr(new int[s.sz]), mx(s.mx), sz(s.sz) {
	for (size_t i=0; i!=sz; ++i)
		arr[i] = s.arr[i];
}

Span& Span::operator=(const Span& s) {
	if (this == &s)
		return (*this);
	int* tmp = new int[s.sz];
	delete[] arr;
	arr = tmp; sz = s.sz; mx = s.mx;
	for (size_t i=0; i!=sz; ++i)
		arr[i] = s.arr[i];
	return (*this);
}

Span::~Span(void) { delete[] arr; }

size_t	Span::size(void) const { return (sz); };

int&	Span::at(unsigned int idx) {
	if (idx >= sz)
		throw (std::out_of_range("Span"));
	return (arr[idx]);
}

const int&	Span::at(unsigned int idx) const {
	if (idx >= sz)
		throw (std::out_of_range("Span"));
	return (arr[idx]);
}

void	Span::addNumber(int n) {
	if (sz == mx)
		throw (std::out_of_range("Span"));
	arr[sz++] = n;
}

unsigned int	Span::shortestSpan(void) const {
	if (sz == 0 || sz == 1)
		throw (NoSpanException());
	unsigned int shortest(span(arr[0], arr[1]));
	for (size_t i=0; i!=sz-1; ++i) {
		for (size_t j=i+1; j!=sz; ++j) {
			shortest = min(shortest, span(arr[i], arr[j]));
		}
	}
	return (shortest);
}

unsigned int	Span::largestSpan(void) const {
	if (sz == 0 || sz == 1)
		throw (NoSpanException());
	unsigned int largest(span(arr[0], arr[1]));
	for (size_t i=0; i!=sz-1; ++i) {
		for (size_t j=i+1; j!=sz; ++j) {
			largest = max(largest, span(arr[i], arr[j]));
		}
	}
	return (largest);
}

unsigned int	Span::span(int a, int b) { return (a - b >= 0 ? a - b : b - a); }

unsigned int	Span::min(unsigned int a, unsigned int b) { return (a < b ? a : b); }

unsigned int	Span::max(unsigned int a, unsigned int b) { return (a > b ? a : b); }

std::ostream& operator<<(std::ostream& os, const Span& s)
{
	if (s.size() == 0)
		return (os << "{}");
	os << "{";
	for (size_t i=0; i!=s.size(); ++i)
		os << s.at(i) << ", ";
	return (os << "\b\b}");
}
