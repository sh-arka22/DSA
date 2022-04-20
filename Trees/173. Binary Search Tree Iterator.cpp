class BSTIterator
{
private:
    list<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        insertAllLeft(root);
    }

private:
    void insertAllLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push_front(node);
            node = node->left;
        }
    }

public:
    int next()
    {
        TreeNode *rn = st.front();
        st.pop_front();
        insertAllLeft(rn->right);
        return rn->val;
    }

    bool hasNext()
    {
        return st.size() != 0;
    }
};
