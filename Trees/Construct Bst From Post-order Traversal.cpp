//PEP-CODING

TreeNode* helper(vector<int>& postorder,int leftRange, int rightRange,int &idx) {
    if(idx < 0 or postorder[idx]<leftRange){
        return nullptr;
    }
    TreeNode* node = new TreeNode(postorder[idx--]);
    node->right = helper(postorder,node->val,rightRange,idx);
    node->left = helper(postorder,leftRange,node->val,idx);
    return node;
}

TreeNode *bstFromPostorder(vector<int> &postorder) {
    int i = postorder.size()-1;
    int lt = -(int)1e9 - 1;
    int rt = (int)1e9 + 1;
    return helper(postorder,-1,1001,i);
}