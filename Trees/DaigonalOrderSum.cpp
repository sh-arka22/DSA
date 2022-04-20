/**
 * Follow up Diagonal Order -> Diagonal order sum 
 * 
 */

vector<int> Diagonal Order(TreeNode* root){
    //vector<vector<int>>ans;
    vector<int>ans;

    if(root == nullptr){
        return ans;
    }
     deque<TreeNode*> que;

     que.push_front(root);

     while(que.size()>0){
        int sz = que.size();

        //vector<int>sAns;
        int sum = 0;

        while(sz-->0){
            TreeNode rn = que.front();
            que.pop_front();

            while(rn != nullptr){
                //sAns.pus_back(rn->val);
                sum += rn->val;
                if(rn->left != nullptr){
                    que.push_back(rn->left);
                }
                rn = rn->left;
            }
        }
        //ans.push_back(sAns);
        ans.push_back(sum);
     }
}
