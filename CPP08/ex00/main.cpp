#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
	std::cout << "--- Testing std::vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Testing std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try {
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Testing const container ---" << std::endl;
	const std::deque<int> deq(vec.begin(), vec.end());
	try {
		std::deque<int>::const_iterator it = easyfind(deq, 20);
		std::cout << "Found value in const deque: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
