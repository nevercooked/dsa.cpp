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
    void dfs(std::vector<int>& values, TreeNode* root) {
        if (!root) return;
        dfs(values, root->left);
        values.push_back(root->val);
        dfs(values, root->right);
    }

    bool isValidBST(TreeNode* root) {
        std::vector<int> values;
        dfs(values, root);
        for (int i = 1; i < values.size(); ++i) {
            if (values[i] <= values[i - 1]) return false;
        }
        return true;
    }
};