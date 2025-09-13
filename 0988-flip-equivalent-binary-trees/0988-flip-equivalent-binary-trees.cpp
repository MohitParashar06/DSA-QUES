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

    void f(TreeNode* root, unordered_map<int,int>& par, TreeNode* parent){
        if(!root) return;
        if(!parent)
            par[root->val] = -1;
        else
            par[root->val] = parent->val;
        f(root->left, par,root);
        f(root->right,par,root);
    }

    bool f1(TreeNode* root, unordered_map<int,int>& par, unordered_map<int,int>& par2, TreeNode* p){
        if(!root) return 1;
        if(!p)
            par2[root->val] = -1;
        else
            par2[root->val] = p->val;
        if(par[root->val] != par2[root->val] )return 0;
        bool l = f1(root->left,par,par2,root);
        bool r = f1(root->right,par,par2,root);
        return l && r;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return 1;
        if(!root1 || !root2) return 0;
        unordered_map<int,int> par,par2;
        f(root1,par,NULL);
        return f1(root2,par,par2,NULL) && par.size() == par2.size();
    }
};