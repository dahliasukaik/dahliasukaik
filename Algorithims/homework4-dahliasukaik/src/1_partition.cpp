#include "searching_algorithms.h"
#include <iostream>
#include <vector>
#include <cstdlib> // for std::rand()
using namespace std;

int partition(vector<int>& arr, int start, int end){
    int rand_index = start + rand() % (end - start + 1);

    swap(arr[rand_index], arr[end]);

    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return (i + 1);
}
