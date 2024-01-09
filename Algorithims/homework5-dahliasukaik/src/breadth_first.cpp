#include "tree_algorithms.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void _breadth_first(TreeNode* root, vector<int>& answer) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        answer.push_back(curr->data);

        // Push the children to the queue
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

vector<int> breadth_first(TreeNode* node) {
    vector<int> answer;
    _breadth_first(node, answer);

    return answer;
}
