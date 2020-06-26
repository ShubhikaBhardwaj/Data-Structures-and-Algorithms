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
    int numComponents(ListNode* head, vector<int>& G) {
        
        unordered_set<int> s;
        for(int i=0;i<G.size();i++)
        {
            s.insert(G[i]);
        }
 
        bool start=true;
        int count=0;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(s.find(cur->val)!=s.end())//present
              {
                  if(start==true)
                    {count++;
                     start=false;
                    }
              }

            else
            {
                start=true;
                
            }
             

            cur=cur->next;
        }

        return count;
        
    }
};