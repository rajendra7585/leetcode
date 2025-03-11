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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            
            
                
                slow=slow->next;
            
        }
        
        ListNode* prev=NULL;
        ListNode* curr=slow;

        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;

        }
        ListNode* temp=head;
        ListNode* temp1=prev;
        while(temp1){
            if(temp->val != temp1->val){return false;}

            temp=temp->next;
            temp1=temp1->next;
        }
        return true;

    }
};