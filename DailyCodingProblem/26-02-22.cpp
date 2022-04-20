/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

/*
LEETCODE HARD: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
297. Serialize and Deserialize Binary Tree
*/

class Codec {
public:
    // Encodes a tree to a single string.
    void dfs(TreeNode* curr,string& s){
        if(!curr){
            s.push_back('*');
            return;
        }
        s.append(to_string(curr->val)+",");
        dfs(curr->left,s);
        dfs(curr->right,s);
    }
    
    string serialize(TreeNode* root) {
        string s="";
        dfs(root,s);
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *decode(string& data){
        if(data.size()==0)  return NULL;
        if(data[0]=='*'){
            data = data.substr(1);
            return NULL;
        }
        int pos = 0;
        string no="";
        while(data[pos]!=',')
            no += data[pos++];
        
        TreeNode *curr = new TreeNode(stoi(no));
        data = data.substr(pos+1);
        curr->left = decode(data);
        curr->right = decode(data);
        return curr;
    }
    
    TreeNode* deserialize(string data) {
        if(data.size()<=1)  return NULL;
        return decode(data);
    }
};