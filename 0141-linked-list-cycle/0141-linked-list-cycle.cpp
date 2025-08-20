/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (slow && fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow == fast;
    }
};