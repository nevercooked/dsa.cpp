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
    void dfs(TreeNode* root, std::vector<int>& values) {
        if (!root) return;
        dfs(root->left, values);
        values.push_back(root->val);
        dfs(root->right, values);
    }
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> values;
        dfs(root, values);
        return values[k - 1];
    }
};