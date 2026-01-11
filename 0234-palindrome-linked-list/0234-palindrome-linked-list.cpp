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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = reverseList(head->next);
        ListNode* fnode = head->next;
        fnode->next = head;
        head->next = NULL;
        return newhead;
    }
   bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL) {
        fast = fast->next;
        if (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    ListNode* temp = reverseList(slow->next);
    ListNode *curr1 = head;
    ListNode *curr2=temp;
    while (curr2!= NULL) {
        if (curr1->val!= curr2->val) {
            reverseList(temp);
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    reverseList(temp);
    return true;
}
}
;