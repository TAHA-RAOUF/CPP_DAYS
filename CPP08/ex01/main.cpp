#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
	std::cout << "--- Subject Test ---" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- Large Scale Test (15,000 numbers) ---" << std::endl;
	{
		Span sp(15000);
		std::vector<int> nums;
		std::srand(std::time(NULL));
		for (int i = 0; i < 15000; ++i) {
			nums.push_back(std::rand());
		}
		sp.addNumber(nums.begin(), nums.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n--- Exception Tests ---" << std::endl;
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try {
			sp.addNumber(3);
		} catch (const std::exception& e) {
			std::cout << "Exception adding extra element: " << e.what() << std::endl;
		}

		Span spEmpty(5);
		try {
			spEmpty.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception empty span: " << e.what() << std::endl;
		}
	}

	return 0;
}
