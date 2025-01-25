#include "ISerializable.h"
#include "ISerializable.cpp"
#include <iostream>

int main() {
    Example example;
    example.data = "Hello, World!";

    std::cout << "Serialized Data: ";
    example.Serialize();

    std::string path = "data.txt";
    example.Serialize(path);

    Example example2;
    example2.Deserialize(path);
    std::cout << "\nDeserialized Data: ";
    example2.Serialize();

    return 0;
}