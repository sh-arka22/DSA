
TreeNode* leftMost(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    while (root != nullptr){
        root = root.left;
    }
    return root;
}

TreeNode* rightMost(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    while(root != nullptr){
        root = root->right;
    }
    return root;
}
//IN BST -> SAME AS CEIL FLOOR 
void predSucc(TreeNode* root,int data){
    TreeNode *curr = root, *succ = nullptr, *pred = nullptr;

    while (curr != null){
        if(curr.val = data){
            TreeNode leftmost = leftMost(curr.right); // the value just greater than curr
            succ = (leftmost != nullptr ? leftMost : succ);

            TreeNode rightmost = rightMost(curr.left);// the value just samller than curr
            pred = (rightmost != nullptr ? rightmost : pred);
        }
        else if(curr.val<data){
            pred = curr;
            curr = curr.right;
        }
        else if(curr.val>data){
            succ = curr;
            curr = curr.left;
        }
    }
    
}