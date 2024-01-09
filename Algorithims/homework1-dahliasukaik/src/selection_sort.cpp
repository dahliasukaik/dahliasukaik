#include "sorting_algorithms.h"

/*
selection_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void selection_sort(vector<int>& nums){
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {

        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }

        std::swap(nums[i], nums[min_index]);
    }
}