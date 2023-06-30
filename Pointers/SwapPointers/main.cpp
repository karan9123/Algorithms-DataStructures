#include <iostream>

/**
 *    swapValues
 *
 *    swap values of two variables
 *
 *    @param val1 - first value
 *    @param val2 - second value
**/
void swapValues(int* val1, int*val2){
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return;
}

int main(){

    int val1, val2;

    std::cout << "Enter value 1: ";
    std::cin >> val1;
    std::cout << "Enter value 2: ";
    std::cin >> val2;

    std::cout << "Before swapping: " << std::endl;
    std::cout << "Value 1: " << val1 << std::endl;
    std::cout << "Value 2: " << val2 << std::endl;

    swapValues(&val1, &val2);
    std::cout << "After swapping: " << std::endl;
    std::cout << "Value 1: " << val1 << std::endl;
    std::cout << "Value 2: " << val2 << std::endl;


    return 0;
}