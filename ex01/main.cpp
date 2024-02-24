#include <iostream>
#include "Span.hpp"

int	main(void)
{
	Span man(10000);
	for (int i=0; i!=10000; ++i)
		man.addNumber(i * 2);
	std::cout << "man: " << man << std::endl;
	std::cout << "man: shortest span: " << man.shortestSpan() << std::endl;
	std::cout << "man: largest span: " << man.largestSpan() << std::endl;
	Span span(5);

	int n(1);

	std::cout << "span: " << span << std::endl;
	try { span.largestSpan();
	} catch (Span::NoSpanException& e) { std::cout << "a.out: largestSpan(): " << e.what() << std::endl; }

	span.addNumber(n *= -2);
	std::cout << "span: " << span << std::endl;
	try { span.largestSpan();
	} catch (Span::NoSpanException& e) { std::cout << "a.out: largestSpan(): " << e.what() << std::endl; }

	for (int i=0; i!=4; ++i) {
		span.addNumber(n *= -2);
		std::cout << "span: " << span << std::endl;
		std::cout << "span: shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "span: largest span: " << span.largestSpan() << std::endl;
	}

	try { span.addNumber(n *= -2);
	} catch (std::out_of_range& e) { std::cout << "a.out: addNumber(): out of range: " << e.what() << std::endl; }

	return (0);
}

