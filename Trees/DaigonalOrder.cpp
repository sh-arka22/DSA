/**
 * Followup question of -> Vertical Order Traversal
 * 
 */
//___________________ In general output_______
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

    vector<vector<int>>diagonalOrder(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        vector<int>minMax(2,0);
        widthofShadow(root,0,minMax);
        int width = abs(minMax[0]) + ; // here the width also change
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
                    que.push_back(vpair(node->right,vl)); //similarly like vertial order but here not (vl+1) only (vl)
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> DiagonalOrder(TreeNode *root) {
        vector<vector<int>>ans = diagonalOrder(root);
        return ans;
    }
};

//__________________________GFG Type output_____________

vector<vector<int>> Diagonal Order(TreeNode* root){
    vector<vector<int>>ans;

    if(root == nullptr){
        return ans;
    }
     deque<TreeNode*> que;

     que.push_front(root);

     while(que.size()>0){
        int sz = que.size();

        vector<int>sAns;
        while(sz-->0){
            TreeNode rn = que.front();
            que.pop_front();

            while(rn != nullptr){
                sAns.pus_back(rn->val);
                if(rn->left != nullptr){
                    que.push_back(rn->left);
                }
                rn = rn->left;
            }
        }
        ans.push_back(sAns);
     }
}