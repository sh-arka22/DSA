#include<iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val){
        this->val = val;
    }
};

bool find(TreeNode* node,int val){
    if(node == nullptr)
        return false;
    if(node->val == val)
        return true;
    return find(node->left,val) or find(node->right,val);
}

void nodeRootPath(TreeNode* node,int data, vector<int>ans){
    if(node == nullptr)
        return;
    if(node->val == data){
        ans.push_back(node->val);
        return;
    }
    if(ans.size()==0){
        nodeRootPath(node->left,data,ans);
    }
    if(ans.size()==0){
        nodeRootPath(node->right,data,ans);
    }
    if(ans.size()>0){
        ans.push_back(node->val);
    }
}