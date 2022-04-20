
unordered_set<TreeNode*>st; // set containing the nodes with water_______________

void getNodesBurned(TreeNode* node,int time, vector<vector<int>>&ans, TreeNode* block){
	if(root == nullptr or root == block or (st.count(block)>0))
		return;
	if(time == ans.size()){
		ans.push_back({});
	}

	ans[time].push_back(root->val);
	getNodesBurned(node->left, time+1,ans,block);
	getNodesBurned(node->right,time+1,ans,block);
}

int find(TreeNode* root,TreeNode* burningNode, vector<vector<int>>&ans){
	if(root == nullptr)
		return -1;
	if(root == burningNode){
		//get every node below this node
		getNodesBurned(root,0,ans,nullptr);
		return 1;
	}

	int left_dis = find(root->left,burningNode,ans);
	int right_dis = find(root->right,burningNode,ans);

	if(left_dis != -1){
		//get nodes
		getNodesBurned(root,left_dis,ans,root->left);
		return left_dis+1;
	}
	if(right_dis != -1){
		//get nodes
		getNodesBurned(root,right_dis,ans,root->right);
		return right_dis+1;
	}
	return -1;
}

void burningTreeWater(TreeNode* root,TreeNode* burningNode,vector<TreeNode*>waterNodes){
	vector<vector<int>> ans;
	for(auto nodes : waterNodes){
		st.insert(nodes);
	}
	find(root, burningNode, ans);
}
