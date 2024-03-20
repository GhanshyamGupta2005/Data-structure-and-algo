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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode* dummy = new ListNode(0);
        dummy->next = list1;
        ListNode* prevA = dummy;
        for (int i = 0; i < a; ++i)
            prevA = prevA->next;
        ListNode* nodeB = prevA->next;
        for (int i = a; i <= b; ++i)
            nodeB = nodeB->next;
        ListNode* endList2 = list2;
        while (endList2->next != nullptr)
            endList2 = endList2->next;
        prevA->next = list2;
        endList2->next = nodeB;
        return dummy->next;
    }
};
