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

    bool isPalindrome(ListNode* head) {
     if(head==NULL||head->next==NULL)
     return true;


      ListNode *mid=middleNode(head);
      ListNode *nhead= mid->next;

      mid->next=NULL;

      nhead=reverseList(nhead);

      ListNode* c1=head;
      ListNode *c2=nhead;

      bool ans=true;

     while(c1!=NULL&&c2!=NULL)
      {
          if(c1->val!=c2->val)
          {
              ans =false;
              break;
          }
         
         c1=c1->next;
         c2=c2->next;
      }

      return ans;
        
    }
};