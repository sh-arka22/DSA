//https://leetcode.com/problems/serialize-and-deserialize-bst/
class Codec
{
public:
    void serialize(TreeNode *root, string &sb)
    {
        if (root == nullptr)
            return;

        sb += to_string(root->val) + " ";
        serialize(root->left, sb);
        serialize(root->right, sb);
    }

    string serialize(TreeNode *root)
    {
        string sb = "";
        serialize(root, sb);
        return sb;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder, int lr, int rr, vector<int> &idx)
    {
        int i = idx[0];
        if (i >= preorder.size() || preorder[i] < lr || preorder[i] > rr)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[i]);
        idx[0]++;

        root->left = bstFromPreorder(preorder, lr, root->val, idx);
        root->right = bstFromPreorder(preorder, root->val, rr, idx);

        return root;
    }

    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return nullptr;
        stringstream ss(data);
        string word;

        vector<int> preorder;
        while (ss >> word)
        {
            int val = stoi(word);
            preorder.push_back(val);
        }

        vector<int> idx(1, 0);
        return bstFromPreorder(preorder, -(int)1e9, (int)1e9, idx);
    }
};
