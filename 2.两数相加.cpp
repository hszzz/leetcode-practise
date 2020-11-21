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
        ListNode* ret = new ListNode(-1);
        ListNode* current = ret;

        bool tag = false;
        while (l1 || l2) {
            current->next = new ListNode((l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0));

            if (tag) {
                current->val += 1;
                tag = false;
            }

            if (current->val >= 10) {
                current->val = current->val % 10;
                tag = true;
            }

            current = current->next;
            l1 != nullptr ? l1 = l1->next : l1;
            l2 != nullptr ? l2 = l2->next : l2;
        }

        if (tag) {
            current->val += 1;
            if (current->val >= 10) {
                current->val = current->val % 10;

                current->next = new ListNode(1);
            }
        }

        if (current->val >= 10) {
            current->val = current->val % 10;

            current->next = new ListNode(1);
        }
        return ret->next;
    }
};