#ifndef SEARCHING_ALGORITHMS_H
#define SEARCHING_ALGORITHMS_H

#include <vector>
#include <climits>
using namespace std;

int partition(vector<int> &nums, int start, int end);
int randomized_select(vector<int> nums, int k, int start, int end);

#endif