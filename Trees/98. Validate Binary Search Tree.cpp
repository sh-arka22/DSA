class Solution {
private:
    TreeNode *getRightMostNode(TreeNode *node, TreeNode *curr){
    while (node->right != nullptr && node->right != curr){
        node = node->right;
    }

    return node;
}
public:
    bool isValidBST(TreeNode *root){
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        bool flag = true;
        while (curr != nullptr){
            TreeNode *left = curr->left;
            if (left == nullptr){

                if (prev != nullptr && prev->val >= curr->val){
                    flag = false;
                }
                prev = curr;

                // cout << curr->val << endl; inorder traversal

                curr = curr->right;
            }
            else{
                TreeNode *rightMostNode = getRightMostNode(left, curr);
                if (rightMostNode->right == nullptr){                                // thread creation block
                    rightMostNode->right = curr; // thread is created

                    curr = curr->left;
                }
                else
                {                                   // thread destroy block
                    rightMostNode->right = nullptr; // thread is cut down

                    if (prev->val >= curr->val)
                    {
                        flag = false;
                    }
                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        return flag;
    }
};