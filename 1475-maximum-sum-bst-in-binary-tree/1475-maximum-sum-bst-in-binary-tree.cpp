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
    // int mini = INT_MAX, maxi = INT_MIN;
    vector<int> solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return {0, 1, (int)1e9, (int)-1e9};
        }
        if (!root->left && !root->right) {
            ans = max(ans, root->val);
            // mini = min(mini, root->val);
            // maxi = max(maxi, root->val);
            return {root->val, 1, root->val, root->val};
        }

        auto p1 = solve(root->left, ans);
        auto p2 = solve(root->right, ans);
        int val = root->val;
        bool fg = false;
        int mini, maxi;
        if (root->right && root->left && val < p2[2] && val > p1[3]) {
            fg = true;
            mini = min({p1[2], p2[2], root->val});
            maxi = max({p1[3], p2[3], root->val});
        } else if (root->right && !root->left && val < p2[2]) {
            fg = true;
            mini = min(p2[2], val);
            maxi = max(p2[3], val);
        } else if (root->left && !root->right && val > p1[3]) {
            fg = true;
            mini = min(p1[2], val);
            maxi = max(p2[3], val);
        }

        if (fg && p1[1] && p2[1]) {
            ans = max(ans, val + p1[0] + p2[0]);
            return {val + p1[0] + p2[0], 1, mini, maxi};
        } else {
            return {0, 0, mini, maxi};
        }
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        auto x = solve(root, ans);
        return ans < 0 ? 0 : ans;
    }
};