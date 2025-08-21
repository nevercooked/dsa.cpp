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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        const auto& dummy = std::make_shared<ListNode>(0, head);
        ListNode* prev    = dummy.get();
        ListNode* end     = dummy.get();
        for (int i = 0; i < n && end; ++i) {
            end = end->next;
        }
        while (end && end->next) {
            prev = prev->next;
            end  = end->next;
        }
        prev->next = prev->next->next;
        return dummy->next;
    }
};