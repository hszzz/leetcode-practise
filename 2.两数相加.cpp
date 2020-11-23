/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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