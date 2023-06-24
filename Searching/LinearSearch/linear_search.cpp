#include <iostream>
#include <vector>

template <typename T>
class LinearSearch
{
private:
    std::vector<T> search_vec;

public:
    LinearSearch(std::vector<T> given_vec) : search_vec(given_vec){};

    int returnPos(const T& target)
    {
        for (int i = 0; i < search_vec.size(); i++)
        {
            if (search_vec[i] == target)
                {
                    return i;
                }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> my_vec = {4, 2, 9, 1, 7, 5};

    LinearSearch<int> linear_search(my_vec);
    int result = linear_search.returnPos(7);

    if (result == -1){
        std::cout << "Could not find element 7 in the list. \n";  
    }else{
        std::cout <<"Element 7 was found at position "<< result << " in the given list. \n";
    }

    return 0;
}