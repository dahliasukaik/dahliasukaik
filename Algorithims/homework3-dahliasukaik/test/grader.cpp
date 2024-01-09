#include <iostream>

#include <vector>
#include <ctime>
#include <cassert>

#include "../src/searching_algorithms.h"
#include "input_generator.h"

using namespace std;

void print(vector<int>& nums){
    for(int num: nums){
        cout << num << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]){
    // check if functions are implemented
    if(_lower_bound({}, 0) == INT_MAX && _upper_bound({}, 0) == INT_MAX){
        cout << "Functions are not yet implemented!\n";
        assert("Functions are not yet implemented!" && argc == 1);
        return 0;
    }

    // initialization
    srand((unsigned) time(NULL));
    
    // configuring test set
    int totalSets = 1000;
    pair<int,int> n_range = {10, 100};
    pair<int,int> val_range = {-100, 100};
    pair<int,int> duplication_range = {2, 5};

    // generating two sets for unique numbers and duplicate numbers
    vector<vector<int>> testSet = get_random_duplicate_set(totalSets, n_range, val_range, duplication_range);

    // sort the inputs 
    for(int i=0; i<testSet.size(); i++)
    sort(testSet[i].begin(), testSet[i].end());

    int totalTests = 0;
    int totalPassed = 0;

    cout << "Testing Lower Bound: ";
    for(vector<int> test: testSet){
        int testOut, trueOut;

        // testing for existing element
        int randomInd = get_random_value({0, test.size()-1});
        testOut = _lower_bound(test, test[randomInd]);
        trueOut = lower_bound(test.begin(), test.end(), test[randomInd]) - test.begin();
        totalTests += 1;
        totalPassed += (testOut == trueOut);
    
        // testing for non-existing element
        int randomNum = get_random_value(val_range);
        testOut = _lower_bound(test, randomNum);
        trueOut = lower_bound(test.begin(), test.end(), randomNum) - test.begin();
        totalTests += 1;
        totalPassed += (
            binary_search(test.begin(), test.end(), randomNum) 
            ? 
                (testOut == trueOut)
            : 
                (testOut == -1)
        );
    }
    cout << totalPassed << " / " << totalTests << " passed\n";
    if(argc>1)
    assert("Lower Bound Failed!" && totalPassed == totalTests);

    totalTests = 0;
    totalPassed = 0;
    cout << "Testing Upper Bound: ";
    for(vector<int> test: testSet){
        int testOut, trueOut;

        // testing for existing element
        int randomInd = get_random_value({0, test.size()-1});
        testOut = _upper_bound(test, test[randomInd]);
        trueOut = upper_bound(test.begin(), test.end(), test[randomInd]) - test.begin() - 1;
        totalTests += 1;
        totalPassed += (testOut == trueOut);
    
        // testing for non-existing element
        int randomNum = get_random_value(val_range);
        testOut = _upper_bound(test, randomNum);
        trueOut = upper_bound(test.begin(), test.end(), randomNum) - test.begin() - 1;
        totalTests += 1;
        totalPassed += (
            binary_search(test.begin(), test.end(), randomNum) 
            ? 
                (testOut == trueOut)
            : 
                (testOut == -1)
        );
    }
    cout << totalPassed << " / " << totalTests << " passed\n";

    if(argc>1)
    assert("Upper Bound Failed!" && totalPassed == totalTests);

    return 0;
}