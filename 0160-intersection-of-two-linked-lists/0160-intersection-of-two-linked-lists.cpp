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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA ,*temp2=headB;
        int len1=0;
        int len2=0;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL){
                len1++;
                temp1=temp1->next;

            }
            if(temp2!=NULL){
                len2++;
                temp2=temp2->next;

            }
        }
        int diff=len1-len2;

        if(diff<0){
            while(diff!=0){
                diff++;
                headB=headB->next;
            }
        }
        else{
            while(diff!=0){
                diff--;
                headA=headA->next;
            }
        }
        while(headA!=NULL || headB!=NULL){
            if(headA==headB)return headB;
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};