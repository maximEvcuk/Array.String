#include"Array.h"

Array::Array(size_t size) : size(size) {
	data = new int[size];
}

Array::Array(size_t size, int minValue, int maxValue) : size(size) {
	data = new int[size];
	fillRandom(minValue, maxValue);
}

Array::Array(const Array& other) : size(other.size) {
	data = new int[size];
	for (size_t i = 0; i < size; ++i){
		data[i] = other.data[i];
	}
}

Array::~Array() {
	delete[] data;
}

void Array::display() const {
	for (size_t i = 0; i < size; ++i) {
		std::cout << data[i] << " ";
	}
		std::cout << std::endl;
}