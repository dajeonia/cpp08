#include <iostream>
#include "Span.hpp"
#include <vector>

int	main(void)
{
	Span man(10000);
	for (int i=0, n=-10000; i!=10000; ++i)
		man.addNumber(n += 2);
	std::cout << "man: " << man << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "man: shortest span: " << man.shortestSpan() << std::endl;
	std::cout << "man: largest span: " << man.largestSpan() << std::endl;

	std::cout << "--------------------------" << std::endl;
	Span empty;
	std::cout << "empty: " << empty << std::endl;

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
	Span span_copy(span);
	std::cout << "span(5): " << span << std::endl;
	std::cout << "span_copy(5): " << span_copy << std::endl;

	std::cout << "-------------------------" << std::endl;
	span.at(2) = 35;
	std::cout << "span[2] = 35;" << std::endl;
	std::cout << "span(5): " << span << std::endl;
	std::cout << "span_copy(5): " << span_copy << std::endl;

	std::cout << "=========================" << std::endl;
	Span span_copy_oper(5);
	span_copy_oper = span;
	std::cout << "span(5): " << span << std::endl;
	std::cout << "span_copy_oper(5): " << span_copy_oper << std::endl;

	std::cout << "-------------------------" << std::endl;
	span.at(3) = 50;
	std::cout << "span[3] = 50;" << std::endl;
	std::cout << "span: " << span << std::endl;
	std::cout << "span_copy_oper(5): " << span_copy_oper << std::endl;

	std::cout << "=========================" << std::endl;
	try {
		Span span_copy_oper_error(9);
		std::cout << "span_copy_oper_error(3): ";
		span_copy_oper_error = span;
 		std::cout << span_copy_oper_error << std::endl;
		std::cout << "-------------------------" << std::endl;
		span.at(3) = 50;
		std::cout << "span[3] = 50;" << std::endl;
		std::cout << "span(5): " << span<< std::endl;
		std::cout << "span_copy_oper_error(3): " << span_copy_oper_error << std::endl;
	} catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }

	std::cout << "=========================" << std::endl;
	try {
		std::cout << "span.addNumber(153): ";
		span.addNumber(153);
		std::cout << span << std::endl;
	} catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }

	std::cout << "=========================" << std::endl;
	std::vector<int> vec(25, 4);
	std::cout << "vec: ";
	for (int i=0; i!=25; ++i)
		std::cout << vec.at(i) << " ";
	std::cout << std::endl;

	Span many(25);
	std::cout << "many(25): ";
	many.addNumber(vec.begin(), vec.end());
	std::cout << many << std::endl;

	try {
		Span many2(24);
		std::cout << "many2(24): ";
		many2.addNumber(vec.begin(), vec.end());
		std::cout << many2 << std::endl;
	} catch (std::exception & e) { std::cout << "exception: " << e.what() << std::endl; }
	std::cout << "=========================" << std::endl;
	return (0);
}
