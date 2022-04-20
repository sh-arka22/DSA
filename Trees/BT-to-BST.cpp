
//--------------Binary Tree To Doubly Linked List-----------------------
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
  // head->left = prev;
  // prev->right = head;

  return head;
}
//______________________________________________________________________

//-----------------------Merge Sort Of Linked List---------------------------
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
//______________________________________________________________________________________

//-------------------------Sorted Doubly Linked List to BST-----------------------------
TreeNode *getMidNode(TreeNode *head){
    if (head == nullptr || head->right == nullptr)
        return head;
    TreeNode *slow = head, *fast = head;
    while (fast->right != nullptr && fast->right->right != nullptr)
    {
        fast = fast->right->right;
        slow = slow->right;
    }

    return slow;
}
  // left : prev, right : next
TreeNode *SortedDLLToBST(TreeNode *head){
    if (head == nullptr || head->right == nullptr)
        return head;

    TreeNode *midNode = getMidNode(head);
    TreeNode *prev = midNode->left, *forw = midNode->right;

    midNode->left = midNode->right = forw->left = nullptr;
    if (prev != nullptr)
        prev->right = nullptr;

    TreeNode *root = midNode, *leftHead = (prev != nullptr ? head : nullptr), *rightHead = forw;

    root->left = SortedDLLToBST(leftHead);
    root->right = SortedDLLToBST(rightHead);

    return root;
}
//_____________________________________________________________________________________


//...........MAIN FUNCTION (BT TO BST)......................................
TreeNode* BST(TreeNode* root){
  TreeNode *DLL = SortedList(root); //Chainging bibary tree to Doubly Linked List
  TreeNode *SDLL = mergeSort(DLL); //Sorting the list wising merge sort

  TreeNode *root = SortedDLLToBST(SDLL); //chainging the sorted doubly linked list to BST

  return root;
}