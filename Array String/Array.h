#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
	int* data;
	size_t  size;
public:
	Array(size_t size = 0);
	Array(size_t size, int minValue, int maxValue);
	Array(const Array& other);

	~Array();

	void display() const;


};

#endif // ARRAY_H
