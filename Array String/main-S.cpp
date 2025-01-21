#include "String.h"

int main() {

	String str1;
	str1.input();
	str1.output();

	String str2(50);
	str2.input();
	str2.output();

	String str3("Hello World!");
	str3.output();

	String str4 = str3;
	str4.output();
	return 0;
}