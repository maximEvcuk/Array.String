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
	void fillRandom(int minValue, int maxValue);

	void sort();
	void resize(size_t newSize);
	int min() const;
	int max() const;

private:
	int customRandom(int minValue, int maxValue);
};

#endif // ARRAY_H
