TreeNode* Merged(TreeNode* l1, TreeNode* l2){
	if(l1 == nullptr or l2 == nullptr){
		return (l1 != nullptr ? l1 : l2);
	}

	TreeNode* dummy = new TreeNode(-1);
	TreeNode* prev = dummy, c1 = l1, c2 = l2;

	while(c1 != NULL and c2 != nullptr){
		if(c1->val <= c2->val){
			prev->right = c1;
			c1->left = prev;
			c1 = c1->right;
			prev = prev->right;
		}
		else{
			prev->right = c2;
			c2->left = prev;
			c2 = c2->right;
			prev = prev->right;
		}
	}

	if(c1 != NULL){
		prev->right = c1;
		c1->left = prev; 
	}
	else{
		prev->right = c2;
		c2->left = prev;
	}

	TreeNode* head = dummy->right;
	dummy->right = head->left = nullptr;


	return head;
}