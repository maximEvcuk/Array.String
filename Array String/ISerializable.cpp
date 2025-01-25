#include "ISerializable.h"
#include <fstream>

class Example : public ISerializable {
public:
    std::string data;

    std::ostream& Serialize(std::ostream& output) override {
        output << data;
        return output;
    }

    std::istream& Deserialize(std::istream& input) override {
        input >> data;
        return input;
    }

    std::ostream& Serialize(std::string& path) override {
        std::ofstream file(path);
        if (file.is_open()) {
            return Serialize(file);
        }
        return std::cout;
    }

    std::istream& Deserialize(std::string& path) override {
        std::ifstream file(path);
        if (file.is_open()) {
            return Deserialize(file);
        }
        return std::cin;

    }

    std::ostream& Serialize() override {
        return Serialize(std::cout);
    }

    std::istream& Deserialize() override {
        return Deserialize(std::cin);
    }

};

