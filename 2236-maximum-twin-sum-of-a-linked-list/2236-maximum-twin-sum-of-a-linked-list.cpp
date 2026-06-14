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
private:
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        while (node != nullptr) {
            ListNode* next = node->next;
            node->next = prev;
            prev       = node;
            node       = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* node = head;
        int       len  = 0;
        while (node != nullptr) {
            node = node->next;
            len += 1;
        }
        node = head;
        for (int i = 0; i < (len / 2) && node != nullptr; ++i) {
            node = node->next;
        }
        if (node == nullptr) {
            throw invalid_argument("Middle node cannot be null!");
        }
        ListNode* left    = head;
        ListNode* right   = reverseList(node); 
        int       twinSum = 0;
        while (left != nullptr && right != nullptr) {
            twinSum = max(twinSum, left->val + right ->val);
            left    = left->next;
            right   = right->next;
        }
        return twinSum;
    }
};