#include <iostream>

/**
 * @brief Dynamically allocates an array of integers based on user input.
 *        Prompts the user to enter the size of the array and allocates memory dynamically using new.
 *        Fills the array with user-provided values.
 */
int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* ptr = new int[size]; // Dynamically allocate memory for the array

    for (int i = 0; i < size; i++) {
        std::cout << "Enter the element: ";
        std::cin >> ptr[i]; // Fill the array with user-provided values
        std::cout << std::endl;
    }

    delete[] ptr; // Free the dynamically allocated memory
    ptr = NULL; // Set the pointer to NULL to avoid dangling pointer issues

    return 0;
}
