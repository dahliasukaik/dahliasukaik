#include "searching_algorithms.h"

/*
Given a vector of integers and a target element, 
return the right most index of target element,
if element does not exist return -1
*/
int _upper_bound(vector<int> nums, int target){

    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {

            result = mid; 

            left = mid + 1; 
        } 
        else if (nums[mid] < target) {
            left = mid + 1; 
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}