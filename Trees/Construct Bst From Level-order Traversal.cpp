TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
{
    int idx = 0;
    queue<levelPair *> que;
    que.push(new levelPair());
    TreeNode *root = nullptr;

    while (que.size() != 0 && idx < arr.size())
    {
        levelPair *pair = que.front();
        que.pop();

        if (arr[idx] < pair->lb || arr[idx] > pair->rb)
            continue;

        TreeNode *node = new TreeNode(arr[idx++]);
        if (pair->par == nullptr)
            root = node;
        else
        {
            if (node->val < pair->par->val)
                pair->par->left = node;
            else
                pair->par->right = node;
        }

        que.push(new levelPair(node, pair->lb, node->val));
        que.push(new levelPair(node, node->val, pair->rb));
    }

    return root;
}