#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void incrementElement(T &elem)
{
	elem += 1;
}

int main()
{
	std::cout << "--- Testing int array ---" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original array: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intLen, incrementElement<int>);
	std::cout << "After increment: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n--- Testing const int array ---" << std::endl;
	int const constIntArray[] = {10, 20, 30};
	std::size_t constIntLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

	std::cout << "Const array: ";
	::iter(constIntArray, constIntLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n--- Testing string array ---" << std::endl;
	std::string strArray[] = {"Hello", "42", "Network"};
	std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
