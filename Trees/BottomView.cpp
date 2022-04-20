//Code Studio -> https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?leftPanelTab=0
class vpair{
public:
    TreeNode *node = nullptr;
    int vl = 0;

    vpair(TreeNode *node,int vl){
        this->node = node;
        this->vl = vl;
    }
};
vector<vector<int>> bottomOrder_Value(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> minMax(2, 0);
    widthOfShadow(root, 0, minMax);
    int width = minMax[1] - minMax[0] + 1;
    vector<vector<int>> ans(width);
    vector<int> hlevel(width, -1); // this store the the horizontal level of a particular vartial

    list<vpair> que;
    que.push_back(vpair(root, abs(minMax[0])));

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            vpair p = que.front();
            que.pop_front();
            TreeNode *node = p.node;
            int vl = p.vl;

            if (level > hlevel[vl])
            {
                ans[vl].clear();
                hlevel[vl] = level;
            }
            ans[vl].push_back(node->val);

            if (node->left != NULL)
                que.push_back(vpair(node->left, vl - 1));
            if (node->right != NULL)
                que.push_back(vpair(node->right, vl + 1));
        }
        level++;
    }

    return ans;
}
vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
    vector<int>ans=
}