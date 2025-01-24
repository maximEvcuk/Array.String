#include "Array.h"

int main() {
    try {
        Array<int> arr1;
        arr1.fillRandom(1, 100);
        std::cout << "Array 1: " << arr1 << std::endl; 
       
        arr1.append(50);
        std::cout << "Array 1 after appending 50: " << arr1 << std::endl;
       
        arr1.erase(2);
        std::cout << "Array 1 after erasing index 2: " << arr1 << std::endl;

        arr1.clear();
        std::cout << "Array 1 after clearing: " << arr1 << std::endl;

        arr1.reserve(20);
        std::cout << "Capacity after reserving 20: " << arr1.getCapacity() << std::endl;

        arr1.append(10);
        arr1.append(20);
        std::cout << "Array 1 after appending values: " << arr1 << std::endl;
 
        arr1.shrink();
        std::cout << "Capacity after shrinking: " << arr1.getCapacity() << std::endl;

        std::cerr << arr1[5] << std::endl;
    }
    catch (const std::runtime_error& e) {
       std::cerr << "Error: " << e.what() << std::endl;
  
    return 0;
}


   

    


