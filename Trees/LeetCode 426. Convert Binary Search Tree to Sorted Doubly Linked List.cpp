//_________________________Using DFS______________________________________

static TreeNode* prev =nullptr;

void dfs(TreeNode* node){
  if(node == nullptr)
    return;
  dfs(node->left);
  prev->right = node;
  node->left = prev;
  prev = node;
  dfs(node->right);
}

TreeNode* SortedList(TreeNode* node){
  TreeNode* dummy = new TreeNode(-1);
  prev = dummy;
  dfs(node);
  TreeNode* head = dummy->right;

  dummy->right = head->left = nullptr; //link destruction between the head and the dummy node

  //creation of the circle
  head->left = prev;
  prev->right = head;

  return head;
}

//_________________Using Stack________________
void dfs(TreeNode* node){
  stack<TreeNode*>st;
  TreeNode* curr = node;
  while(st.size()>0 or curr != nullptr){
    while(curr!=nullptr){
      st.push(curr);
      curr = curr->left;
    }

    prev->right = curr;
    curr->left = prev;
    prev = curr;

    curr = curr->right;
  }
}

TreeNode* SortedList(TreeNode* node){
  TreeNode* dummy = new TreeNode(-1);
  prev = dummy;
  dfs(node);
  TreeNode* head = dummy->right;

  dummy->right = head->left = nullptr; //link destruction between the head and the dummy node

  //creation of the circle
  head->left = prev;
  prev->right = head;

  return head;
}

//__________________________________Using MorisTraversal___________________________________
