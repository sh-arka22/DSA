class Solution {
private:
    TreeNode* constructor(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd) {
        if(inStart>inEnd)
            return nullptr;

        int idx = inStart;
        while(inorder[idx] != preorder[preStart])
            idx++;

        int left = idx - inStart; // counts the total no of nodes in the left sub->tree

        TreeNode *node = new TreeNode(preorder[preStart]);

        node->left = constructor(preorder, inorder, preStart+1, preStart+left, inStart, idx-1);
        node->right = constructor(preorder, inorder, preStart+left+1, preEnd, idx+1, inEnd);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        return constructor(preorder,inorder,0,n-1,0,n-1);
    }
};