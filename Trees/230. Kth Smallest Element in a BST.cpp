class Solution {
public:
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        int lt = kthSmallest(root->left, k);
        if(lt)
            return lt;
        cnt++;
        if(cnt==k)
            return root->val;
        int rt = kthSmallest(root->right, k);
        if(rt)
            return rt;
        
        return 0;
    }
};