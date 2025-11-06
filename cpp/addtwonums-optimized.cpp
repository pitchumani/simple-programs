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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        while (l1 || l2 || carry) {
            int digit = carry;
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit / 10;
            curr->next = new ListNode(digit % 10);
            curr = curr->next;
        }
        return dummyHead->next;
    }
};
