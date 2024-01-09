#include "sorting_algorithms.h"

vector<int> aux;
/*  
merge function will merge two sorted sub-arrays, 
one starts from `low` and goes until `mid`
second starts from `mid+1` and goes until `high`
e.g.
    1   4 6  8     3 5 7
    ^        ^         ^
    low      mid       high

@Parameters:
    nums: a reference to the vector of numbers
    low: start point of first sub-array
    mid: end of left-sub-array
    high: end of right-sub-array

@Returns:
    the function does NOT return anything
    it merges the sub-arrays in-place.
*/
void merge(vector<int>& nums, int low, int mid, int high){
    //middle index minus first index -> 3-0 = 3
    // but we actually have 4 elements so we add 1 to account for it since the first index starts at zero 
    int left_size = mid - low + 1;
    int right_size = high - mid;

    std::vector<int> left(left_size);
    std::vector<int> right(right_size);
    //first sub array , we do low + i because sometimes the vector we want to sort will start at a different index
    for (int i = 0; i < left_size; ++i) {
        left[i] = nums[low + i];
    }
    //second sub array

/*For i = 0, nums[mid + 1 + i] becomes nums[4] which is 2 (first element of the right subarray).
For i = 1, nums[mid + 1 + i] becomes nums[5] which is 4 (second element of the right subarray).*/
    for (int i = 0; i < right_size; ++i) {
        right[i] = nums[mid + 1 + i];
    }

    int L = 0, R = 0, k = low;

    while (L < left_size && R < right_size) {
        //if the left array element is less than or equal to the right array element put the 
        if(left[L] <= right[R]) {
            nums[k++] = left[L++];

        }
        //else because the right first element is less that the left first element so the right element goes into the nums array
        else {
            nums[k++] = right[R++];
        }
    }
// If there are still unprocessed elements in the left subarray after the above loop
// (i.e., if the right subarray got exhausted first), this loop ensures they get added to nums.
    while (L < left_size) {
        nums[k++] = left[L++];
    }
//Similarly, if there are unprocessed elements in the right subarray after the main merging loop, 
//this loop ensures they get added to nums.
    while (R < right_size) {
        nums[k++] = right[R++];
    }
}

/*
merge_sort function will sort the array in-place in the given bounds
@Parameters:
    nums: a reference to the vector of integers to be sorted
    low: start index of the array to be sorted
    high: end index of the array to be sorted
@Returns:
    void. 
    the algorithm sorts the vector in-place. so, it does not return anything.
*/
void _merge_sort(vector<int>& nums, int low, int high){
    //low is the first index 
   // high is the last index
   //statement ensures there are more than one element
    if (low < high) {
        // this gets the middle element 
        int mid = low + (high - low) / 2;
    //recursive call to this function to instead of passing the last element it passes middle 
        _merge_sort(nums, low, mid);
    
        _merge_sort(nums, mid + 1, high);

        merge(nums, low, mid, high);

    }
}

/*
merge_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void merge_sort(vector<int>& nums){
    aux.resize(nums.size(), 0);
    _merge_sort(nums, 0, nums.size()-1);
}