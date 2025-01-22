#include "Array.h"

int main() {
    Array arr1(10);
    arr1.fillRandom(1, 100);
    std::cout << "Array 1: " << arr1 << std::endl;

    Array arr2 = arr1;
    arr2.sort();
    std::cout << "Sorted Array 2: " << arr2 << std::endl;

    std::cout << "Min: " << arr2.min() << std::endl;
    std::cout << "Max: " << arr2.max() << std::endl;

    Array arr3(5, 1, 50);
    std::cout << "Array 3: " << arr3 << std::endl;

    Array arr4 = arr1 + arr3;
    std::cout << "Combined Array (arr1 + arr3): " << arr4 << std::endl;

    arr1 += arr3;
    std::cout << "Array 1 after +=: " << arr1 << std::endl;

    std::cout << "Element at index 2 in Array 1: " << arr1[2] << std::endl;

    if (arr1 == arr2) {
        std::cout << "Array 1 is equal to Array 2." << std::endl;
    }
    else {
        std::cout << "Array 1 is not equal to Array 2." << std::endl;
    }

    if (arr1 != arr3) {
        std::cout << "Array 1 is not equal to Array 3." << std::endl;
    }

    if (arr1 > arr3) {
        std::cout << "Array 1 is longer than Array 3." << std::endl;
    }
    else {
        std::cout << "Array 1 is not longer than Array 3." << std::endl;
    }

    Array commonArray = arr1 * arr3;
    std::cout << "Common elements between Array 1 and Array 3: " << commonArray << std::endl;
	return 0;

}