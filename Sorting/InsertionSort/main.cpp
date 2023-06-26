#include <iostream>
#include <vector>

/**
 * @brief Sorts a vector of integers using the Insertion Sort algorithm.
 *
 * @param my_vec The vector to be sorted.
 */
void insertionSort(std::vector<int>& my_vec) {
    int size = my_vec.size();
    int temp;
    int j;
    
    for (int i = 1; i < size; i++) {
        temp = my_vec[i];
        j = i - 1;
        
        while (j >= 0) {
            if (j == 0) {
                // If we've reached the beginning of the vector,
                // check if the first element is greater than the current element.
                // If so, swap them; otherwise, insert the current element.
                if (my_vec[0] > temp) {
                    my_vec[1] = my_vec[0];
                    my_vec[0] = temp;
                    break;
                } else {
                    my_vec[1] = temp;
                    break;
                }
            }
            
            if (my_vec[j] > temp) {
                // Shift the elements greater than the current element to the right.
                my_vec[j + 1] = my_vec[j];
                j--;
            } else {
                // Insert the current element at the appropriate position.
                my_vec[j + 1] = temp;
                break;
            }
        }
    }
}

int main() {
    std::vector<int> my_vec = {15, 5, 24, 8, 1, 3, 16, 10, 20}; // Example vector to be sorted
    insertionSort(my_vec); // Sort the vector using Insertion Sort

    // Print the sorted vector
    for (int i = 0; i < my_vec.size(); i++) {
        std::cout << my_vec[i];
        
        if (i != my_vec.size() - 1) {
            std::cout << ", ";
        }
    }
    
    return 0;
}
