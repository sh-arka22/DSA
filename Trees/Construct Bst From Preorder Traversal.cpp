class Solution {
private:
    // int idx = 0;
    TreeNode* helper(vector<int>& preorder,int leftRange, int rightRange,int &idx) {
        if(idx >= preorder.size() or preorder[idx]>rightRange){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = helper(preorder,leftRange,node->val,idx);
        node->right = helper(preorder,node->val,rightRange,idx);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder,-1,1001,i);
    }
};