#include "sorting_algorithms.h"

/*
insertion_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void insertion_sort(vector<int>& nums){

    int n = nums.size();
    for(int i = 1; i < n; i++) {
        int key = nums[i];
        int prev_ind = i - 1;

        while (prev_ind >= 0 && nums[prev_ind] > key) {
            nums[prev_ind + 1] = nums[prev_ind];
            prev_ind = prev_ind - 1; 
        }

        nums[prev_ind + 1] = key;
    }
}