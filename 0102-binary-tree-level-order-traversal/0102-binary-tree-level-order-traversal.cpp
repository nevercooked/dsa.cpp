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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> nodes;
        std::deque<TreeNode*>         dq;
        dq.push_front(root);
        while (!dq.empty()) {
            std::vector<int> values; 
            int              size = dq.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = dq.front();
                values.push_back(node->val);
                dq.pop_front();
                if (node->left)  dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            }
            nodes.push_back(std::move(values));
        }
        return nodes;
    }
};