#ifndef TREE_ALGORITHMS_H
#define TREE_ALGORITHMS_H

#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void _inorder(TreeNode* node, vector<int>& answer);
void _preorder(TreeNode* node, vector<int>& answer);
void _postorder(TreeNode* node, vector<int>& answer);

void _breadth_first(TreeNode* node, vector<int>& answer);

vector<int> inorder(TreeNode* node);
vector<int> preorder(TreeNode* node);
vector<int> postorder(TreeNode* node);

vector<int> breadth_first(TreeNode* node);

#endif