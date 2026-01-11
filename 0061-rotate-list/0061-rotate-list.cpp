class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // 1. Find length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2. Normalize k
        k = k % len;
        if (k == 0)
            return head;

        // 3. Find new tail (len - k - 1)
        ListNode* curr = head;
        for (int i = 0; i < len - k - 1; i++) {
            curr = curr->next;
        }

        // 4. Rotate
        ListNode* newHead = curr->next;
        curr->next = NULL;
        tail->next = head;

        return newHead;
    }
};
