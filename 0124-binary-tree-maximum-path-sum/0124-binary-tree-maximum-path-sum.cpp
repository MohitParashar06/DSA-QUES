/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int& ans) {
        if (!root)
            return -1e9;
        if (root->left == NULL && root->right == NULL) {
            ans = max(ans, root->val);
            return root->val;
        }

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        int ls = left + root->val;
        int rs = right + root->val;

        ans = max(ans, left);
        ans = max(ans, right);
        ans = max(ans, ls);
        ans = max(rs, ans);
        ans = max(ans, left + right + root->val);
        ans = max(ans,root->val);
        // cout << root->val << "->"
        //      << max({ls, rs, root->val, left, right, left + right + root->val})
        //      << endl;

        if (ls > rs) {
            ans = max(ans, ls);
            return max(ls,root->val);
        } else if (rs >= ls) {
            ans = max(ans, rs);
            return max(root->val,rs);
        } else {
            ans = max(ans, left + right + root->val);
            return 0;
        }
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        int x = solve(root, ans);
        return ans;
    }
};