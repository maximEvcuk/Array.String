#include "String.h"

String::String() {
	length = 80;
	str = new char[length + 1];
	std::memset(str, 0, length + 1);
}

String::String(size_t size) {
	length = size;
	str = new char[length + 1];
	std::memset(str, 0, length + 1);
}

String::String(const char* initStr) {
	length = std::strlen(initStr);
	str = new char[length + 1];
	std::strcpy(str, initStr);
}

String::String(const String& other) {
	length = other.length;
	str = new char[length + 1];
	std::strcpy(str, other.str);
}

void String::input() const {
	std::cout << "Enter a  string: " << std::endl;
	std::cin.getline(str, length + 1);
}

void String::output() const {
	std::cout << str << std::endl;
}

size_t String::getLength() const {
	return length;
}