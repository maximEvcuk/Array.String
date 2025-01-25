#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <iostream>
#include <string>

class ISerializable {
public:
    virtual std::ostream& Serialize(std::ostream& output)  = 0;
    virtual std::istream& Deserialize(std::istream& input) = 0;
    virtual std::ostream& Serialize(std::string& path) = 0;
    virtual std::istream& Deserialize(std::string& path) = 0;
    virtual std::ostream& Serialize() = 0;
    virtual std::istream& Deserialize() = 0;
    virtual ~ISerializable() = default;

};

#endif // ISERIALIZABLE_H