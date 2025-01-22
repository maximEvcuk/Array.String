//#ifndef STRING_H
//#define STRING_H
//
//#include <iostream>
//#include <cstring>
//
//class String {
//private:
//	char* str;
//	size_t length;
//
//public:
//	String();
//	String(size_t size);
//	String(const char* initStr);
//	String(const String& other);
//	String(String&& other) noexcept;
//	String& operator=(const String& other);
//	String& operator=(String&& other) noexcept;
//	~String();
//
//
//	String operator+(const String& other) const ;
//	String& operator+=(const String& other);
//	char operator[](size_t index) const;
//	friend std::ostream& operator<<(std::ostream& os, const String& str);
//	bool operator==(const String& other) const;
//	bool operator!=(const String& other) const;
//	bool operator>(const String& other) const;
//	bool operator<(const String& other) const;
//	void input() ;
//	void output() const;
//	size_t getLength() const;
//};
//
//
//#endif // STRING_H