//Pepcoding Portal
//___________________________________Using BFS_____________________________________________
class vPair{
public:
    TreeNode* node;
    int vl = 0;

    vPair(TreeNode* node, int vl){
        this->node = node;
        this->vl = vl;
    }
};
void width(TreeNode* root,int vl, vector<int>&minMax){
    if(root == nullptr){
        return;
    }
    minMax[0] = min(vl,minMax[0]);
    minMax[1] = max(vl,minMax[1]);

    width(root->left,vl-1,minMax);
    width(root->right,vl+1,minMax);
}

vector<int> verticalOrderSum(TreeNode *root){
    vector<int>minMax(2,0);
    width(root,0,minMax);

    int HoriWidth = minMax[1] - minMax[0] + 1;

    vector<int>ans(HoriWidth,0);
    deque<vPair>que;
    que.push_front(vPair(root,abs(minMax[0])));

    while(que.size()>0){
        int sz = que.size();

        while(sz-->0){
            TreeNode* node = que.front().node;
            int vl = que.front().vl;
            que.pop_front();

            ans[vl] += node->val;

            if(node->left){
                que.push_back(vPair(node->left,vl-1));
            }
            if(node->right){
                que.push_front(vPair(node->right,vl+1));
            }
        }
    }
    return ans;
}

//________________________Recursive Solution__________________________________
class vPair{
public:
    TreeNode* node;
    int vl = 0;

    vPair(TreeNode* node, int vl){
        this->node = node;
        this->vl = vl;
    }
};
void width(TreeNode* root,int vl, vector<int>&minMax){
    if(root == nullptr){
        return;
    }
    minMax[0] = min(vl,minMax[0]);
    minMax[1] = max(vl,minMax[1]);

    width(root->left,vl-1,minMax);
    width(root->right,vl+1,minMax);
}

vector<int> verticalOrderSum(TreeNode *root){
    vector<int>minMax(2,0);
    width(root,0,minMax);

    int HoriWidth = minMax[1] - minMax[0] + 1;

    vector<int>ans(HoriWidth,0);
    //............................
}

//_________________________________Beautiful Solution_______________________________________




