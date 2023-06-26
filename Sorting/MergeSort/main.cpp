#include <iostream>
#include <vector>

/**
 * @brief Merge function to merge two sorted subarrays into one sorted array.
 *
 * @param arr The array to be sorted.
 * @param lb The lower bound of the subarray.
 * @param mid The middle index of the subarray.
 * @param ub The upper bound of the subarray.
 */
void merge(std::vector<int> &arr, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = 0;
    std::vector<int> temp(ub - lb + 1);

    // Merge the two subarrays into a temporary array in sorted order
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements from the first subarray
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements from the second subarray
    while (j <= ub)
    {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements from the temporary array back to the original array
    for (int i = 0; i < k; i++)
    {
        arr[lb + i] = temp[i];
    }
}

/**
 * @brief Recursive function to perform merge sort on the array.
 *
 * @param arr The array to be sorted.
 * @param lb The lower bound of the subarray.
 * @param ub The upper bound of the subarray.
 */
void mergeSort(std::vector<int> &arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = static_cast<int>((lb + ub) / 2);

        // Recursively divide the array into two halves and sort them
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);

        // Merge the two sorted subarrays
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    std::vector<int> arr = {15, 5, 24, 8, 1, 3, 16, 10, 20};

    // Sort the array using merge sort
    mergeSort(arr, 0, 8);

    // Print the sorted array
    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << ", ";
    }

    return 0;
}
