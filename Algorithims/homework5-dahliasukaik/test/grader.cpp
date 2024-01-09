#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include <fstream>
#include <functional>
#include <ctime>
#include <cassert>

#include "../src/tree_algorithms.h"
#include "input_generator.h"

using namespace std;

#define test_input_type vector<int>
#define testfn_type function<vector<int>(TreeNode*)>

#define range pair<int,int>

TreeNode* build(vector<int> input){
    if(input.size() == 0) return nullptr;

    int total = input.size();
    int current = 0;
    queue<TreeNode*> que;
    
    // adding root to queue
    TreeNode* root = new TreeNode(input[current++]);
    que.push(root);

    // we iterate through all levels and add childrens
    // until we are done
    while(current != total){
        TreeNode* parent = que.front();
        TreeNode* child;

        // add left child
        child = new TreeNode(input[current++]);
        parent -> left = child;
        que.push(child);

        if(current == total) break;

        // add right child
        child = new TreeNode(input[current++]);
        parent -> right = child;
        que.push(child);

        // remove the parent node from que
        que.pop();
    }

    return root;
}

void read(vector<vector<int>>& testSet, ifstream& file){
    string line;
    while(getline(file, line)){
        vector<int> nums;
        int num = 0;
        for(int i=0; i<line.length(); i++){
            if(line[i] == ' '){
                nums.push_back(num);
                num = 0;
            }else{
                num *= 10;
                num += (line[i] - '0');
            }
        }
        testSet.push_back(nums);
    }
}

int main(int argc, char* argv[]){
    // adding all test functions
    map<string, testfn_type> test_fns;
    test_fns["inorder"] = inorder;
    test_fns["preorder"] = preorder;
    test_fns["postorder"] = postorder;
    test_fns["breadth_first"] = breadth_first;

    vector<vector<int>> testSet;
    ifstream testInputsFile;
    testInputsFile.open("./test/tests.txt");
    read(testSet, testInputsFile);

    int testIndex = 0;
    for(pair<string, testfn_type> candidate: test_fns){
        string testName = candidate.first;
        testfn_type testFn = candidate.second;
        cout << "Testing: " << testName << " ";
        testIndex ++;

        int totalPassed = 0;
        int totalTests = 0;
        for(int i=0; i<testSet.size(); i+=5){
            TreeNode* root = build(testSet[i]);
            totalTests += 1;

            vector<int> testOutput = testFn(root);
            vector<int> trueOutput = testSet[i+testIndex];

            if(testOutput.size() == trueOutput.size()){
                bool isOk = true;
                
                for(int i=0; i<trueOutput.size(); i++){
                    if(trueOutput[i] != testOutput[i]){
                        isOk = false;
                    }
                }

                if(isOk)
                totalPassed += 1;
            }
        }

        cout << "(" << totalPassed << " / " << totalTests << " passed)\n";

        if(argc > 1){
            assert(totalPassed == totalTests);
        }
    }


    return 0;
}