// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>

// #include <fstream>
// #include <functional>
// #include <ctime>
// #include <cassert>

// #include "../src/tree_algorithms.h"
// #include "input_generator.h"

// using namespace std;

// #define test_input_type vector<int>
// #define testfn_type function<vector<int>(TreeNode*)>

// #define range pair<int,int>

// TreeNode* build(vector<int> input){
//     int total = input.size();
//     int current = 0;
//     queue<TreeNode*> que;
    
//     // adding root to queue
//     TreeNode* root = new TreeNode(input[current++]);
//     que.push(root);

//     // we iterate through all levels and add childrens
//     // until we are done
//     while(current != total){
//         TreeNode* parent = que.front();
//         TreeNode* child;

//         // add left child
//         child = new TreeNode(input[current++]);
//         parent -> left = child;
//         que.push(child);

//         if(current == total) break;

//         // add right child
//         child = new TreeNode(input[current++]);
//         parent -> right = child;
//         que.push(child);

//         // remove the parent node from que
//         que.pop();
//     }

//     return root;
// }

// void write(vector<int> nums, ofstream& file){
//     for(int num: nums){
//         file << num << " ";
//     }
//     file << "\n";
// }

// void generate(){
//     // initialization
//     srand((unsigned) time(NULL));

//     // parameters for test
//     int totalSets = 100;
//     range n_range = {10, 100};
//     range val_range = {0, 100};

//     // adding all test functions
//     map<string, testfn_type> test_fns;
//     test_fns["inorder"] = inorder;
//     test_fns["preorder"] = preorder;
//     test_fns["postorder"] = postorder;
//     test_fns["breadth_first"] = breadth_first;

//     // generating random input testset
//     vector<test_input_type> testSet = get_random_set(totalSets, n_range, val_range);
//     int totalPassed;

//     // opening a file to write tests
//     ofstream testsOutput;
//     testsOutput.open("./gh_tests.txt");

//     for(vector<int> test: testSet){        
//         TreeNode* root = build(test);
        
//         write(test, testsOutput);
//         for(pair<string, testfn_type> candidate: test_fns){
//             string testName = candidate.first;
//             testfn_type testFn = candidate.second;

//             vector<int> traversal = testFn(root);
//             write(traversal, testsOutput);
//         }
//     }
// }