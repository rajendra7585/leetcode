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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenhead=new ListNode(-1), *eventail=evenhead;
        ListNode* oddhead=new ListNode(-1), *oddtail=oddhead;
        ListNode* curr=head, *temp;
        int c=0;
        while(curr){
            temp=curr;
            curr=curr->next;
            temp->next=NULL;
            c++;
            if(c &1){
                oddtail->next=temp;
                oddtail=temp;
            }
            else{
                eventail->next=temp;
                eventail=temp;
            }
        }
        oddtail->next=evenhead->next;
        return oddhead->next;

    }
};