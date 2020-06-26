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
   ListNode* midNode(ListNode* head)
   {
       ListNode* slow=head;
       ListNode* fast=head;

       while(fast->next!=NULL&&fast->next->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
       }
       return slow;
   }

   ListNode* reverseLL(ListNode* head)
   {
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
        

        ListNode* mid=midNode(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;

        nhead=reverseLL(nhead);

        ListNode* temp=new ListNode(-1);
        ListNode* ans=temp;

        ListNode* c1=head;
        ListNode* c2=nhead;

        while(c1!=NULL&&c2!=NULL)
        {
            temp->next=c1;
            c1=c1->next;
            temp=temp->next;

            temp->next=c2;
            c2=c2->next;
            temp=temp->next;            

        }

        if(c1!=NULL)
        {
            temp->next=c1;
           // c1=c1->next;
            temp=temp->next;

        }

        if(c2!=NULL)
        { temp->next=c2;
           // c2=c2->next;
            temp=temp->next;            

        }

       head=ans->next;
        
    }
};