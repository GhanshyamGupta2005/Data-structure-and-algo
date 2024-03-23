class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        vector<int> v;
        ListNode* p = head;
        while (p != nullptr) {
            v.push_back(p->val);
            p = p->next;
        }

        int i = 0;
        int j = v.size() - 1;
        p = head;
        while (i < j) {
            p->val = v[i++];
            p = p->next;
            p->val = v[j--];
            p = p->next;
        }
        // If the length of the list is odd, handle the middle element.
        if (i == j) {
            p->val = v[i];
        }
    }
};
