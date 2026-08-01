#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
	std::cout << "--- MutantStack Subject Test ---" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n--- std::list Comparison Test ---" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "top (back): " << lst.back() << std::endl;

		lst.pop_back();

		std::cout << "size: " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n--- Reverse Iterator Test ---" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("world!");
		mstack.push("Hello");

		for (MutantStack<std::string>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
			std::cout << *rit << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
