
#include "Array.h"
#include <cstdlib>

template<typename T>
Array<T>::Array(size_t size, size_t initialCapacity) : size(size), capacity(initialCapacity) {
    data = new T[capacity];
}

template<typename T>
Array<T>::Array(size_t size, T minValue, T maxValue) : size(size), capacity(size) {
    data = new T[capacity];
    fillRandom(minValue, maxValue);
}

template<typename T>
Array<T>::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Array<T>::Array(Array&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
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
    if (newSize > capacity) {
        reserve(newSize);
    }
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
size_t Array<T>::getSize() const {
    return size;
}

template<typename T>
size_t Array<T>::getCapacity() const {
    return capacity;
}


template<typename T>
void Array<T>::append(const T& value) {
    if (size >= capacity) {
        reserve(capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void Array<T>::erase(size_t index){
    if (index < size){
        for (size_t i = index; i < size - 1; ++1) {
            data[i] = data[i + 1];
        }
        --size;
    }
}

template<typename T>
void Array<T>::clear(){
    size = 0;
}

template<typename T>
void Array<T>::reserve(size_t newCapacity){
    if (newCapacity > capacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template<typename T>
void Array<T>::shrink(){
    if (size < capacity) {
        T* newData = new T[size];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = size;
    }
}



template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
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
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
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
    for (size_t i = 0; i < other.size; ++i) {
        append(other.data[i]);
    }
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
bool Array<T>::operator!=(const Array& other) const {
    return !(*this == other);
}

template<typename T>
bool Array<T>::operator>(const Array& other) const {
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