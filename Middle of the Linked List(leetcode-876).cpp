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
        ListNode *p,*q;
        p=q=head;
        if(head==nullptr)
        return nullptr;

        while(p&&p->next!=nullptr)
        {
           q=q->next;
           p=p->next;
           p=p?p->next:p;
        }
        return q;
    }
};



