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
      
      void reverse(ListNode *q,ListNode *p,ListNode *&ptr)
      {
          if(p)
          {
              reverse(p,p->next,ptr);
              p->next=q;
          }

          else
          ptr =q;
      }
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr=nullptr;
        reverse(0,head,ptr);
        return ptr;
    }
};
