//#ifndef ARRAY_H
//#define ARRAY_H
//
//#include <iostream>
//
//class Array {
//private:
//	int* data;
//	size_t  size;
//public:
//	Array(size_t size = 0);
//	Array(size_t size, int minValue, int maxValue);
//	Array(const Array& other);
//
//	~Array();
//
//	void display() const;
//	void fillRandom(int minValue, int maxValue);
//
//	void sort();
//	void resize(size_t newSize);
//	int min() const;
//	int max() const;
//
//	Array& operator=(const Array& other);
//
//	Array operator+(const Array& other) const;
//
//	Array& operator+=(const Array& other);
//
//	int operator[](size_t index) const;
//
//	friend std::ostream& operator<<(std::ostream& os, const Array& arr);
//
//	bool operator==(const Array& other) const;
//
//	bool operator!=(const Array& other) const;
//
//	bool operator>(const Array& other) const;
//
//	bool operator<(const Array& other) const;
//
//	Array operator*(const Array& other) const;
//
//private:
//	int customRandom(int minValue, int maxValue);
//};
//
//#endif // ARRAY_H
