/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(int &ind, vector<int>& pre, vector<int>& in, int s, int e){
        if(s > e || ind < 0){
            return NULL;
        }
        int x = pre[ind--];
        TreeNode* newnode = new TreeNode(x);
        int id = -1;
        for(int i = s; i <= e; i++){
            if(in[i] == x)
                id = i;
        }
        // cout << id << " " << ind << " " << s << " " << e << " " << x << endl;
        newnode->right = solve(ind,pre,in,id+1,e);
        newnode->left = solve(ind,pre,in,s,id-1);
        return newnode;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int ind = in.size()-1;
        return solve(ind,post,in,0,in.size()-1);
    }
};