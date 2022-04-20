TreeNode* mergeSort(TreeNode* head){
	if(head == nullptr or head->right == nullptr){
		return head;
	}
	TreeNode* midNode = getMid(head);
	TreeNode* forHead = midNode->right;

	forHead->left = nullptr, midNode->right = nullptr;
	TreeNode* leftFaith = mergeSort(head);
	TreeNode* rightFaith = mergeSort(forHead);

	TreeNode* mergedHead = Merged(leftFaith,rightFaith);

	return mergedHead;
}