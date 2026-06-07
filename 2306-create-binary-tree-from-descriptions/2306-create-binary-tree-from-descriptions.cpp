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
private:
    struct NodeChildren {
        int left;
        int right;
        NodeChildren() : left(-1), right(-1) {}
    };
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, NodeChildren> graph;
        set<int>                         childs;
        set<int>                         parents;
        for (const auto& desc : descriptions) {
            int  parent = desc[0];
            int  child  = desc[1];
            bool isLeft = desc[2];
            if (isLeft) {
                graph[parent].left = child;
            }
            else {
                graph[parent].right = child;
            }
            parents.insert(parent);
            childs.insert(child);
        }
        vector<int> roots;
        set_difference(parents.begin(), parents.end(), childs.begin(), childs.end(), back_inserter(roots));
        if (roots.size() != 1) {
            return nullptr;
        }
        TreeNode* root   = new TreeNode(roots[0]);
        queue<TreeNode*> fifo;
        fifo.push(root);
        while (!fifo.empty()) {
            int size = fifo.size();
            for (int i = 0; i < size; ++i) {
                TreeNode*    node     = fifo.front();
                NodeChildren children = graph[node->val];
                fifo.pop();
                if (children.left != -1) {
                    node->left = new TreeNode(children.left);
                    fifo.push(node->left);
                }
                if (children.right != -1) {
                    node->right = new TreeNode(children.right);
                    fifo.push(node->right);
                }
            }
        }
        return root;
    }
};