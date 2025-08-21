/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const auto&            dummy = std::make_shared<ListNode>();
        ListNode*              ptr   = dummy.get();
        std::vector<ListNode*> nodes(lists.begin(), lists.end());
        while (!std::all_of(nodes.begin(), nodes.end(), [](ListNode* node) -> bool { return node == nullptr; })) {
            ListNode* minimumNode = nullptr;
            int       idx = 0;
            for (int i = 0; i < nodes.size(); ++i) {
                const auto& node = nodes[i];
                if (node == nullptr) {
                    continue;
                }
                if (minimumNode == nullptr || node->val < minimumNode->val) {
                    minimumNode = node;
                    idx         = i;
                }
            }
            ptr->next  = minimumNode;
            ptr        = ptr->next;
            nodes[idx] = nodes[idx]->next; 
            ptr->next  = nullptr;
        }
        return dummy->next;
    }
};