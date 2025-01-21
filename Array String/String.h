#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
	char* str;
	size_t length;

public:
	String();

	String(size_t size);

	String(const char* initStr);

	String(const String& other);


	void input() const;
	void output() const;

	size_t getLength() const;
};


#endif // STRING_H