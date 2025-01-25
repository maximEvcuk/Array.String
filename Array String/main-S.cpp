#include <iostream>
#include <fstream>
#include "String.h"

int main() {
    try {

        String str1;
        str1.input();
        str1.output();

        std::ofstream outFile("string_data.txt");
        if (outFile.is_open()) {
            str1.Serialize(outFile);
            outFile.close();
        }



        String str2;
        std::ifstream inFile("string_data.txt");
        if (inFile.is_open()) {
            str2.Deserialize(inFile);
            inFile.close();
        }

        std::cout << "Deserialized String: ";
        str2.output();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}