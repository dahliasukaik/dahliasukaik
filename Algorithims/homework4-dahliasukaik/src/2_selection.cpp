#include "searching_algorithms.h"
#include <iostream>
#include <vector>
#include <cstdlib> // for rand
#include <ctime> 
#include <algorithm>

using namespace std;

int partition_2(vector<int>& nums, int start, int end) {
    // Select a random pivot_index from start to end
    int pivot_idx = start + rand() % (end - start + 1);
    std::swap(nums[pivot_idx], nums[end]);
    int pivot = nums[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (nums[j] <= pivot) {
            i++;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[end]);
    return i + 1;
}


int randomized_select(vector<int> nums, int k, int start, int end) {
    if (start > end) {
        return -1; // Invalid index, should not happen in correct usage
    }

    int pos = partition_2(nums, start, end);
    int left = pos - start;
    
    if (k == left) {
        return nums[pos];
    }
    else if (k < left) {
        return randomized_select(nums, k, start, pos - 1);
    }
    else {
        return randomized_select(nums, k - left - 1, pos + 1, end);
    }
}
