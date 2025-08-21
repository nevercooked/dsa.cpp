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
    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reverseList(ListNode*& head) {
        ListNode* ptr = nullptr;
        while(head) {
            ListNode* tmp = ptr;
            ptr           = std::exchange(head, head->next);
            ptr->next     = tmp;
        }
        head = ptr;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* middle = getMiddleNode(head); 
        ListNode* left   = head;
        ListNode* right  = std::exchange(middle->next, nullptr);
        reverseList(right);
        while (left && right) {
            ListNode* tmp    = left->next;
            left->next       = std::exchange(right, right->next);
            left->next->next = tmp;
            left             = tmp;
        }
    }
};