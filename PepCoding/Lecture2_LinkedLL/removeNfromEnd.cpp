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


    ListNode* removeNthFromEnd(ListNode* head, int n) {

       if(head==NULL|head->next==NULL)  //base case->imp!!!
       return NULL;


        ListNode* slow=head;
        ListNode* fast=head;

        while(n-->0)
          fast=fast->next;

        //gap of n created

        ListNode *prev=NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {   prev=slow;
            slow=slow->next;
            fast=fast->next;
        }  

        if(fast==NULL)  //when node to be removed is head
        {
            return head->next;
        }
        
        ListNode* rm=slow;
        prev->next=rm->next;

        rm->next=NULL;
        delete rm;

        return head;
    }
};