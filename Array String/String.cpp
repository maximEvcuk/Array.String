#include "String.h"

String::String() {
    length = 80;
    str = new char[length + 1];
    if (!str) throw std::bad_alloc();
    std::memset(str, 0, length + 1);
}

String::String(size_t size) {
    length = size;
    str = new char[length + 1];
    if (!str) throw std::bad_alloc();
    std::memset(str, 0, length + 1);
}

String::String(const char* initStr) {
    length = std::strlen(initStr);
    str = new char[length + 1];
    if (!str) throw std::bad_alloc();
    std::copy(initStr, initStr + length, str);
    str[length] = '\0';
}

String::String(const String& other) {
    length = other.length;
    str = new char[length + 1];
    if (!str) throw std::bad_alloc();
    std::copy(other.str, other.str + length, str);
    str[length] = '\0';
}

String::String(String&& other) noexcept
    : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        if (!str) throw std::bad_alloc();
        std::copy(other.str, other.str + length, str);
        str[length] = '\0';
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}

String::~String() {
	delete[] str;
}

String String::operator+(const String& other) const {
    String newString(length + other.length);
    std::copy(str, str + length, newString.str);
    std::copy(other.str, other.str + other.length, newString.str + length);
    return newString;
}

String& String::operator+=(const String& other) {
    size_t newLength = length + other.length;
    char* newStr = new char[newLength + 1];
    if (!newStr) throw std::bad_alloc();
    std::copy(str, str + length, newStr);
    std::copy(other.str, other.str + other.length, newStr + length);
    newStr[newLength] = '\0';

    delete[] str;
    str = newStr;
    length = newLength;
    return *this;
}

char String::operator[](size_t index) const {
    if (index < length) {
        return str[index];
    }
    throw std::out_of_range("Index out of bounds");
}

std::ostream& operator<<(std::ostream& os, const String& str){
	os << str.str;
	return os;
}

bool String::operator==(const String& other) const {
	return length == other.length && std::strcmp(str, other.str) == 0;
}

bool String::operator!=(const String& other) const{
	return !(*this == other);
}

bool String::operator>(const String& other) const{
	return length > other.length;
}

bool String::operator<(const String& other) const {
	return length < other.length;
}

void String::input()  {
	std::cout << "Enter a  string: ";
	std::cin.getline(str, length + 1);
}

void String::output() const {
	std::cout << str << std::endl;
}

size_t String::getLength() const {
	return length;
}