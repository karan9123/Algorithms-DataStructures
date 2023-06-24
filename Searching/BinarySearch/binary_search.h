#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

/**
 * Binary Search
 * 
 * A class that implements the binary search algorithm.
 * The search is performed on a sorted vector of elements.
 * It provides both iterative and recursive versions of the search.
 * 
 * @tparam T The type of elements in the vector.
 */
template <typename T>
class BinarySearch {
private:
    std::vector<T> search_vec; /**< The vector of elements to be searched. */

    /**
     * Recursive Binary Search
     * 
     * Recursively searches for the target element within a given range.
     * 
     * @param low The lower index of the range.
     * @param high The upper index of the range.
     * @param target The target element to search for.
     * @return The index of the target element if found, or -1 if not found.
     */
    int recursiveSearch(int low, int high, const T& target) {
        if (low == high) {
            if (search_vec[low] == target) {
                return low;
            } else {
                return -1;
            }
        } else {
            int mid = static_cast<int>((low + high) / 2);

            if (search_vec[mid] == target) {
                return mid;
            } else if (search_vec[mid] > target) {
                high = mid - 1;
                return recursiveSearch(low, high, target);
            } else if (search_vec[mid] < target) {
                low = mid + 1;
                return recursiveSearch(low, high, target);
            } else {
                return -1;
            }
        }
    }

public:
    /**
     * Constructor
     * 
     * Constructs a BinarySearch object with the given vector.
     * 
     * @param given_vec The vector of elements to be searched.
     */
    BinarySearch(std::vector<T> given_vec) : search_vec(given_vec) {}

    /**
     * Iterative Binary Search
     * 
     * Performs the binary search iteratively.
     * 
     * @param target The target element to search for.
     * @return The index of the target element if found, or -1 if not found.
     */
    int returnPos(const T& target) {
        int low = 0;
        int high = search_vec.size() - 1;

        while (low <= high) {
            int mid = static_cast<int>((low + high) / 2);
            if (search_vec[mid] == target) {
                return mid;
            } else if (search_vec[mid] > target) {
                high = mid - 1;
            } else if (search_vec[mid] < target) {
                low = mid + 1;
            }
        }
        return -1;
    }

    /**
     * Recursive Binary Search
     * 
     * Performs the binary search recursively.
     * 
     * @param target The target element to search for.
     * @return The index of the target element if found, or -1 if not found.
     */
    int returnPosRecursive(const T& target) {
        return recursiveSearch(0, search_vec.size() - 1, target);
    }
};

#endif /* BINARY_SEARCH_H */
