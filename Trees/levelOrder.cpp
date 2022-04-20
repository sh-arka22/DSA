class Solution {
private:
    void bfs(TreeNode* root, vector<vector<int>>&ans){
        deque<TreeNode*> mem;
        mem.push_front(root);

        while(mem.size()>0){
            int sz = mem.size();
            vector<int>level;
            while(sz-->0){
                TreeNode* parr = mem.front();
                mem.pop_front();
                level.push_back(parr == nullptr ? 0:parr->val);
                if(parr->left != nullptr){
                    mem.push_back(parr->left);
                }
                if(parr->right != nullptr){
                    mem.push_back(parr->right);
                }
            }
            ans.push_back(level);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>>ans;
        bfs(root,ans);

        return ans;
    }
};