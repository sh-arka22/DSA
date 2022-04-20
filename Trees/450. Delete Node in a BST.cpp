class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }

        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(root->left == nullptr or root->right == nullptr){
                TreeNode *newNode = root->left != nullptr ? root->left : root->right;
                root->left = root->right = nullptr;
                delete root;
                return newNode;
            }
        }
    }
};