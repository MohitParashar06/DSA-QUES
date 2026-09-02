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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        auto node = root;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({node,0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            auto n = front.first;
            int lvl = front.second;
            mp[lvl] = n->val;
            if(n->left){
                q.push({n->left,lvl+1});
            }
            if(n->right){
                q.push({n->right,lvl+1});
            }
        }
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};