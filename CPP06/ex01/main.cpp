#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.id = 42;
    data.name = "Test Data";
    data.value = 3.14159;

    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Original data values: " << std::endl;
    std::cout << "  id: " << data.id << std::endl;
    std::cout << "  name: " << data.name << std::endl;
    std::cout << "  value: " << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << ptr << std::endl;

    if (ptr == &data) {
        std::cout << "\nSuccess: Deserialized pointer matches the original pointer!" << std::endl;
        std::cout << "Deserialized data values: " << std::endl;
        std::cout << "  id: " << ptr->id << std::endl;
        std::cout << "  name: " << ptr->name << std::endl;
        std::cout << "  value: " << ptr->value << std::endl;
    } else {
        std::cerr << "\nError: Deserialized pointer does NOT match original pointer!" << std::endl;
        return 1;
    }

    return 0;
}
