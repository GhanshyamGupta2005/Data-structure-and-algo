//https://www.youtube.com/watch?v=5UWEVMg10rY&t=1183s&ab_channel=codestorywithMIK
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
    ListNode* removeZeroSumSublists(ListNode* head) {

     int prefixSum=0;

     ListNode* dummyNode=new ListNode(0);
     dummyNode->next=head;
     unordered_map<int,ListNode*>map;
     map[0]=dummyNode;
     while(head)
     {
        prefixSum+=head->val;
        if(map.find( prefixSum)!=map.end())
        {
            // delete wala kaam

            ListNode* start=map[prefixSum]; // past me dekha hai ise
            ListNode*temp=start; // ise dodate hai ab
            int pSum=prefixSum;
            while(temp!=head)
            {
                temp=temp->next;
                pSum+=temp->val;
                if(temp!=head) // head ko dlet kren ke jrut nhi hai
                map.erase(pSum);
            }
            
           start->next=head->next;
        }
        else
        map[ prefixSum]=head;

        head=head->next;

     }
        return dummyNode->next;
    }
};
