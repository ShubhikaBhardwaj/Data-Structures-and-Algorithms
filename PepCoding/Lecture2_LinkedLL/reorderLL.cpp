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
   ListNode* middleNode(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
        
    }

      ListNode* reverseList(ListNode* head) {

        ListNode* cur=head;
        ListNode* prev=NULL;

        while(cur!=NULL)
        {
           ListNode* frwd=cur->next;

           cur->next=prev;

           prev=cur;
           cur=frwd;

        }
        
        return prev;
   
        
    }


    void reorderList(ListNode* head) {

        if(head==NULL||head->next==NULL)
        return;
        //return head;

        ListNode* mid=middleNode(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;

        nhead=reverseList(nhead);

        ListNode* c1=head;
        ListNode* c2=nhead;

        while(c1!=NULL&&c2!=NULL)
        {
            ListNode* f1=c1->next;
            ListNode* f2=c2->next;

            c1->next=c2;
            c2->next=f1;

            c1=f1;
            c2=f2;

        }

       // return head;
    }
};