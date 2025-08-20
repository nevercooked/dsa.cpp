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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        const auto& dummy = std::make_shared<ListNode>(0, list1);
        ListNode*   ptr1  = dummy.get();
        ListNode*   ptr2  = list2;
        while (ptr1 && ptr1->next && ptr2) {
            if (ptr2->val > ptr1->next->val) {
                ptr1 = ptr1->next;
            }
            else {
                ListNode* tmp = ptr2->next;
                ptr2->next = std::exchange(ptr1->next, ptr2);
                ptr2       = tmp;
            }
        }
        while (ptr2) {
            ptr1->next = std::exchange(ptr2, ptr2->next);
            ptr1       = ptr1->next;
        }
        return dummy->next;
    }
};