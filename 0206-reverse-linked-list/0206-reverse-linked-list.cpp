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
        if(head==NULL || head->next==NULL)return head;
        ListNode* fnode=NULL,*curr=head,*back=NULL;
        while(curr!=NULL){
            fnode=curr->next;
            curr->next=back;
            back=curr;
            curr=fnode;
        }
        return back;
        
    }
};