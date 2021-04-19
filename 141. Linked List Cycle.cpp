/**
 * https://leetcode.com/problems/linked-list-cycle/
*/

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
        if (head == nullptr)
            return false;
        
        bool ret = false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while ( (fast != nullptr) && (fast->next != nullptr)) 
        {
            if (slow == fast)
            {
                ret = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return ret;
    }
};
