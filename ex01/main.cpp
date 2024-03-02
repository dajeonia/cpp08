#include <iostream>
#include "Span.hpp"

int	main(void)
{
	Span man(500);
	for (int i=0, n=-500; i!=500; ++i)
		man.addNumber(n += 2);
	std::cout << "man: " << man << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "man: shortest span: " << man.shortestSpan() << std::endl;
	std::cout << "man: largest span: " << man.largestSpan() << std::endl;

	Span span(5);
	for (int i=0, n=1; i!=6; ++i) {
		try {
		if (i != 0) span.addNumber(n *= -2);
		// std::cout << "(i, n): (" << i << "," << n << ")" << std::endl;

		std::cout << "-------------------------" << std::endl;
		std::cout << "span: " << span << std::endl;
		std::cout << "span: shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "span: largest span: " << span.largestSpan() << std::endl;
		} catch (Span::NoSpanException& e) { std::cout << "exception: " << e.what() << std::endl; }
	}

	std::cout << "=========================" << std::endl;
	try {
		std::cout << "span.addNumber(153): ";
		span.addNumber(153);
		std::cout << span << std::endl;
	} catch (std::out_of_range& e) { std::cout << "out of range: " << e.what() << std::endl; }

	std::cout << "=========================" << std::endl;
	return (0);
}

