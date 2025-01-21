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
	for (size_t i = 0; i < size; ++i) {
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
    for (size_t i = 0; i < size; ++i) {
        data[i] = customRandom(minValue, maxValue);
    }
}

int Array::customRandom(int minValue, int maxValue) {
    static unsigned int seed = 12345;
    seed = (seed * 1103515245 + 12345) % 2147483648;
    return minValue + (seed % (maxValue - minValue + 1));
}


void Array::resize(size_t newSize) {
    int* newData = new int[newSize];
    size_t minSize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

void Array::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int Array::min() const {
    int minValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

int Array::max() const {
    int maxValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}


Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array Array::operator+(const Array& other) const{
    size_t newSize = size + other.size;
    Array newArray(newSize);
    for (size_t i = 0; i < size; ++i) {
        newArray.data[i] = data[i];
    }
    for (size_t i = 0; i < other.size; ++i) {
        newArray.data[size + i] = other.data[i];
    }
    return newArray;
}

Array& Array::operator+=(const Array& other) {
    size_t newSize = size + other.size;
    int* newData = new int[newSize];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    for (size_t i = 0; i < other.size; ++i) {
        newData[size + i] = other.data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
    return *this;
}

int Array::operator[](size_t index) const {
    if (index < size) {
        return data[index];
    }
    throw std::out_of_range("Index out of bounds");
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
	for (size_t i = 0; i < arr.size; ++i) {
		os << arr.data[i] << " ";
	}
	return os;
}

bool Array::operator==(const Array& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
	return !(*this == other);
}

bool Array::operator>(const Array& other) const {
    return size > other.size;
}

bool Array::operator<(const Array& other) const {
    return size < other.size;
}


Array Array::operator*(const Array& other) const {
    size_t newSize = 0;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < other.size; ++j) {
            if (data[i] == other.data[j]) {
                newSize++;
                break;
            }
        }
    }
    Array commonArray(newSize);
    size_t index = 0;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < other.size; ++j) {
            if (data[i] == other.data[j]) {
                commonArray.data[index++] = data[i];
                break;
            }
        }
    }
    return commonArray;
}