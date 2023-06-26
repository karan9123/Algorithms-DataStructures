#include <iostream>
#include <vector>

/**
 * @brief Sorts a vector of integers using the bubble sort algorithm.
 * 
 * @param vec The vector to be sorted.
 */
void bubbleSort(std::vector<int>& vec)
{
    int size = vec.size(); // Get the size of the vector
    int k = 0; // Variable to keep track of the number of iterations

    // Iterate through the vector
    for (int i = 0; i < size - 1; i++) {
        // Compare adjacent elements and swap them if they are in the wrong order
        for (int j = 1; j < size - k; j++) {
            if (vec[j - 1] > vec[j]) {
                std::swap(vec[j - 1], vec[j]);
            }
        }
        k++;
    }
}

int main()
{
    std::vector<int> my_vec = {15, 5, 24, 8, 1, 3, 16, 10, 20}; // Example vector to be sorted
    bubbleSort(my_vec); // Sort the vector using bubble sort

    // Print the sorted vector
    for (int i = 0; i < my_vec.size(); i++) {
        std::cout << my_vec[i];
        if (i != my_vec.size() - 1) {
            std::cout << ", ";
        }
    }
}
