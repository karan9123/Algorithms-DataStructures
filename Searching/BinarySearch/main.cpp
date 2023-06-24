#include <iostream>
#include "binary_search.h"

int main() {
    std::vector<int> my_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    BinarySearch<int> binary_search(my_vec);
    int result = binary_search.returnPosRecursive(7);

    if (result == -1) {
        std::cout << "Could not find element 7 in the list." << std::endl;
    } else {
        std::cout << "Element 7 was found at position " << result << " in the given list." << std::endl;
    }

    return 0;
}
