TreeNode* constructor(vector<int>&inorder,int start, int end){
    if(start>end)
        return nullptr;

    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(inorder[mid]); // created the node

    //connnected the node
    root->left = constructor(inorder,start,mid-1);
    root->right = constructor(inorder,mid+1,end);

    return root;
}

TreeNode *constructFromInOrder(vector<int> &in){
    int n = in.size();
    return constructor(in,0,n-1);
}
