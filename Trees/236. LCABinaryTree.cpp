class Solution {
private:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL)
        return NULL;
    if(root == p or root == q)
        return root;
    TreeNode* lSub = LCA(root->left,p,q);
    TreeNode* rSub = LCA(root->right,p,q);
    if(lSub != NULL and rSub != NULL)
        return root;
    if(lSub != NULL)
        return lSub;
    if(rSub != NULL)
        return rSub;
    return NULL;
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
};