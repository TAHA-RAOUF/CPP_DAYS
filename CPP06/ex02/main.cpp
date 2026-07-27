#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
    int choice = std::rand() % 3;
    if (choice == 0) {
        std::cout << "Generated class A" << std::endl;
        return new A();
    } else if (choice == 1) {
        std::cout << "Generated class B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated class C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "=== Running identification tests ===" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        Base* p = generate();
        if (p == NULL) {
            std::cout << "Generation failed!" << std::endl;
            continue;
        }

        std::cout << "Identify by pointer: ";
        identify(p);

        std::cout << "Identify by reference: ";
        identify(*p);

        delete p;
    }

    std::cout << "\n=== Running test with null/invalid pointers ===" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Identify NULL pointer: ";
    identify(nullPtr);

    return 0;
}
