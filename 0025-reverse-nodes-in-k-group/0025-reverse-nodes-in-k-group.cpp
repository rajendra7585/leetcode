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
   ListNode* reversel(ListNode* head, int k){
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* forward=NULL;
    while(k--){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return head;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL && count<k){
            count++;
            temp=temp->next;
        }
        if(count<k)return head;
        ListNode* newHead=reversel(head,k);
        head->next=reverseKGroup(temp,k);
        return newHead;
    }
};