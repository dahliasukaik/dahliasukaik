#include <iostream>

#include <vector>
#include <ctime>
#include <cassert>

#include "../src/searching_algorithms.h"
#include "input_generator.h"

#define test_input_type vector<int>
#define range pair<int,int>

using namespace std;

void print(vector<int>& nums){
    for(int num: nums){
        cout << num << " ";
    }
    cout << "\n";
}

bool checkPartition(vector<int> nums, int pivot){
    for(int i=0; i<pivot; i++){
        if(nums[i] > nums[pivot]) return false; 
    }

    for(int i=pivot+1; i<nums.size(); i++){
        if(nums[i] < nums[pivot]) return false;
    }

    return true;
}

int main(int argc, char* argv[]){
    // initialization
    srand((unsigned) time(NULL));

    // parameters for test
    int totalSets = 1000;
    range n_range = {10, 100};
    range val_range = {0, 100};

    // generating random input testset
    vector<test_input_type> testSet;
    int totalPassed;

    // testing partition
    cout << "Testing Partition: ";
    testSet = get_random_set(totalSets, n_range, val_range);
    totalPassed = 0;    
    for(test_input_type test: testSet){
        int p_index = partition(test, 0, test.size()-1);
        totalPassed += checkPartition(test, p_index);
    }
    cout << totalPassed << " / " << totalSets << " passed\n";
    if(argc > 1) assert("Partition Failed!" && (totalPassed == totalSets));

    // testing selection algorithm
    cout << "Testing Selection: ";
    testSet = get_random_set(totalSets, n_range, val_range);
    totalPassed = 0;
    for(test_input_type test: testSet){
        int randomInd = get_random_value({0, test.size()-1});

        int testOut = randomized_select(test, randomInd, 0, test.size()-1);

        sort(test.begin(), test.end());
        int trueOut = test[randomInd];
        totalPassed += (testOut == trueOut);
    }
    cout << totalPassed << " / " << totalSets << " passed\n";
    if(argc > 1) assert("Selection Failed!" && (totalPassed == totalSets));
    return 0;
}