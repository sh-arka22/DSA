//pepecoding
public static Node getMid(Node node){
      if(node == null || node.right == null){
          return node;
      }
      Node slow = node, fast = node;
      while(fast.right != null && fast.right.right != null){
          slow = slow.right;
          fast = fast.right.right;
      }
      return slow;
  }

  // left : prev, right : next
  public static Node SortedDLLToBST(Node head) {
      if(head == null || head.right == null){
          return head;
      }
      
      Node mid = getMid(head);
      Node prev = mid.left;
      Node forw = mid.right;
      
      //disconnection the the node
      forw.left = null;
      mid.right = null;
      
      if(prev != null){
          prev.right = null;
      }
      mid.left = null;
      
      
      Node Lhead = prev == null ? null : head;
      Node Rhead = forw;
      
      //mackng the connection
      mid.left = SortedDLLToBST(Lhead);
      mid.right = SortedDLLToBST(Rhead);
      

     return mid;
  }

  //_________________________C++_____________
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