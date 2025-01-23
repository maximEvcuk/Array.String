#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template<typename T> 
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t size = 0);
    Array(size_t size, T minValue, T maxValue);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    void display() const;
    void fillRandom(T minValue, T maxValue);
    void resize(size_t newSize);
    void sort();
    T min() const;
    T max() const;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);
    T operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (size_t i = 0; i < arr.size; ++i) {
            os << arr.data[i] << " ";
        }
        return os;
	}
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator>(const Array& other) const;
    bool operator<(const Array& other) const;
    Array operator*(const Array& other) const;

private:
    T customRandom(T minValue, T maxValue);
};



#include "Array.cpp"

#endif // ARRAY_H