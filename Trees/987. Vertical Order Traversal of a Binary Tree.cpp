
// This solution will not handle the nodes of a vertival in sorted manner
//https://www.lintcode.com/problem/651/
class vpair{
public:
    TreeNode *node = nullptr;
    int vl = 0;

    vpair(TreeNode *node,int vl){
        this->node = node;
        this->vl = vl;
    }
};
class Solution {
private:
    void widthofShadow(TreeNode* root, int vl, vector<int> &minMax) {
        if(root == nullptr){
            return;
        }
        minMax[0] = min(minMax[0],vl);
        minMax[1] = max(minMax[1],vl);

        widthofShadow(root->left,vl-1,minMax);
        widthofShadow(root->right,vl+1,minMax);
    }

    vector<vector<int>>verticalOrder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int>minMax(2,0);
        widthofShadow(root,0,minMax);
        int width = minMax[1] - minMax[0] + 1;
        vector<vector<int>>ans(width);

        deque<vpair> que;
        que.push_back(vpair(root, abs(minMax[0]))); //i passed the root vertical level as the abs(of the left most verical)

        while(que.size()>0){
            int size = que.size();
            while(size-- >0){
                vpair par = que.front();
                que.pop_front();

                TreeNode *node = par.node;
                int vl = par.vl;

                ans[vl].push_back(node->val);
                if(node->left != nullptr){
                    que.push_back(vpair(node->left,vl-1));
                }
                if(node->right != nullptr){
                    que.push_back(vpair(node->right,vl+1));
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>>ans = verticalOrder(root);
        return ans;
    }
};

//considerring that the nodes in a vertical are sorted
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
