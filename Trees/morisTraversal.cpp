//i need to do

TreeNode* rightMost(TreeNode* node, TreeNode* curr){
	while(node->right != NULL or node->right != curr){
		node = node->right;
	}
	return node;
}
vector<int> morisOrder(TreeNode* root){
	vector<int>inOrder;

	TreeNode* curr = root;
	while(curr != NULL){
		TreeNode* left = curr->left;

		if(left == nullptr){
			ans.push_back(curr->val);
			curr = curr->right;
		}
		else{
			TreeNode* rtmost = rightMost(left,curr);

			if(rtmost->right == nullptr){ //thread creation
				rtmost->right = curr;
				curr = left;
			}
			else if(rtmost->right == curr){// destruction of thread
				ans.push_back(curr->val);
				rtmost.right = nullptr;
				curr = curr->right;
			}
		}
	}
	return ans;
}