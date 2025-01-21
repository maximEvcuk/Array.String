#include "Array.h"

int main() {
	Array arr1(10);
	arr1.fillRandom(1, 100);
	arr1.display();

	
	Array  arr2 = arr1;
	arr2.sort();
	arr2.display();

	std::cout << "Min: " << arr2.min() << std::endl;
	std::cout << "Max: " << arr2.max() << std::endl;

	return 0;

}