#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	std::cout << "--- Test 1: Construction with no parameter ---" << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	std::cout << "\n--- Test 2: Construction with size parameter ---" << std::endl;
	Array<int> intArray(5);
	std::cout << "Int array size: " << intArray.size() << std::endl;
	std::cout << "Default values in int array: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- Test 3: Modifying elements ---" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = (i + 1) * 10;

	std::cout << "Modified int array: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- Test 4: Copy construction & Assignment ---" << std::endl;
	Array<int> copyArray(intArray);
	Array<int> assignedArray;
	assignedArray = intArray;

	intArray[0] = 999;
	std::cout << "Original intArray[0]: " << intArray[0] << std::endl;
	std::cout << "Copy copyArray[0] (should be 10): " << copyArray[0] << std::endl;
	std::cout << "Assigned assignedArray[0] (should be 10): " << assignedArray[0] << std::endl;

	std::cout << "\n--- Test 5: Out of bounds exception ---" << std::endl;
	try
	{
		std::cout << intArray[100] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: String Array ---" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "CPP";
	strArray[1] = "Module";
	strArray[2] = "07";
	for (unsigned int i = 0; i < strArray.size(); ++i)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	return 0;
}
