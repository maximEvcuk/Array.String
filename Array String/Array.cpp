#include "Array.h"
#include <cstdlib>

template<typename T>
Array<T>::Array(size_t size) : size(size) {
    data = new T[size];
}

template<typename T>
Array<T>::Array(size_t size, T minValue, T maxValue) : size(size) {
    data = new T[size];
    fillRandom(minValue, maxValue);
}

template<typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Array<T>::Array(Array&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

template<typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Array<T>::fillRandom(T minValue, T maxValue) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = customRandom(minValue, maxValue);
    }
}

template<typename T>
T Array<T>::customRandom(T minValue, T maxValue) {
    return minValue + (std::rand() % (maxValue - minValue + 1));
}

template<typename T>
void Array<T>::resize(size_t newSize) {
    T* newData = new T[newSize];
    size_t minSize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

template<typename T>
void Array<T>::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template<typename T>
T Array<T>::min() const {
    T minValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

template<typename T>
T Array<T>::max() const {
    T maxValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

template<typename T>
Array<T> Array<T>::operator+(const Array& other) const {
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

template<typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
    size_t newSize = size + other.size;
    T* newData = new T[newSize];
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

template<typename T>
T Array<T>::operator[](size_t index) const {
    if (index < size) {
        return data[index];
    }
    throw std::out_of_range("Index out of bounds");
}

template<typename T>
bool Array<T>::operator==(const Array& other) const {
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

template<typename T>
bool Array<T>::operator !=(const Array& other) const {
    return !(*this == other);
}

template<typename T>
bool Array<T>::operator >(const Array& other) const {
    return size > other.size;
}

template<typename T>
bool Array<T>::operator<(const Array& other) const {
    return size < other.size;
}

template<typename T>
Array<T> Array<T>::operator*(const Array& other) const {
    size_t newSize = 0;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < other.size; ++j) {
            if (data[i] == other.data[j]) {
                newSize++;
                break;
            }
        }
    }
    Array<T> commonArray(newSize);
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