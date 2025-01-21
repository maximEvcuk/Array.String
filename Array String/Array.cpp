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

void Array::fillRandom(int minValue, int maxValue) {
	for (size_t i = 0; i < size; ++i){
		data[i] = customRandom(minValue, maxValue);
	}
}


int Array::customRandom(int minValue, int maxValue) {
	static unsigned int seed = 12345;

	seed = (seed * 1103515245 + 12345) % 2147483648;

	return  minValue + (seed % (maxValue - minValue + 1));
}


void Array::resize(size_t newSize){
	int* newData = new int[newSize];
	size_t minSize = (newSize < size) ? newSize : size;
	for (size_t i = 0; i < minSize; ++i){
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	size = newSize;

}

void Array::sort(){
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - 1 - i; ++j) {
			if (data[j] > data[j + 1]) {
				// Ξαμ³ν ελεμενς³β
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

}

int Array::min() const{
	int minValue = data[0];
	for (size_t i = 1; i < size; ++i) {
		if (data[i] < minValue) {
			minValue = data[i];
		}
	}
	return minValue;

}


int Array::max() const{
	int maxValue = data[0];
	for (size_t i = 1; i < size; ++i) {
		if (data[i] > maxValue) {
			maxValue = data[i];
		}
	}
	return maxValue;

}