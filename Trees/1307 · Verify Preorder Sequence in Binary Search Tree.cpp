//https://www.lintcode.com/problem/1307/
______________________________________	REVICE___________________________________
class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
    	int n = preorder.size();
    	stack<int>st;
    	int root = -(int)1e9;

    	for(int i=0;i<n;i++){
    		if(preorder[i]<root){
    			return false;
    		}

    		while(st.size()>0 and st.top()<preorder[i]){
    			root = st.top();
    			st.pop();
    		}

    		st.push(preorder[i]);
    	}
    	return true;
    }
};