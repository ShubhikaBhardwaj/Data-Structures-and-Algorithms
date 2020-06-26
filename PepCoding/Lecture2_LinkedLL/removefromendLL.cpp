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
        if(head==NULL||head->next==NULL)
            return NULL;      
        
        //gap strategy
        ListNode* slow=head;
        ListNode* fast=head;

        while(n-->0)
        { fast=fast->next;
        }
        
        if(fast==NULL)//remove head
        {
            return head->next;
        }
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* rm=slow->next;
        slow->next=rm->next;
        rm->next=NULL;
        delete rm;

        return head;
        
    }
};