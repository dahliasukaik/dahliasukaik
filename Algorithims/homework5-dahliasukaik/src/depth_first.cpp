#include "tree_algorithms.h"

void _inorder(TreeNode* node, vector<int>& answer){
    if(node == nullptr) return;

    _inorder(node->left, answer);
    answer.push_back(node->data);
    _inorder(node->right, answer);
}


// TODO
void _preorder(TreeNode* node, vector<int>& answer){
   if(node == nullptr) return;
   answer.push_back(node->data);
   _preorder(node->left, answer);
   _preorder(node->right, answer);

}

// TODO
void _postorder(TreeNode* node, vector<int>& answer){
    if(node == nullptr) return;
   _postorder(node->left, answer);
   _postorder(node->right, answer);
    answer.push_back(node->data);

}

vector<int> inorder(TreeNode* node){
    vector<int> answer;
    _inorder(node, answer);

    return answer;
}

vector<int> preorder(TreeNode* node){
    vector<int> answer;
    _preorder(node, answer);

    return answer;
}

vector<int> postorder(TreeNode* node){
    vector<int> answer;
    _postorder(node, answer);

    return answer;
}
