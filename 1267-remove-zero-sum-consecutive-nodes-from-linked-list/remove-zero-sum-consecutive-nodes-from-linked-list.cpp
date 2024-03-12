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
        ListNode* start = new ListNode();
        start->next = head;
        int pref = 0;
        ListNode*curr = head;
        unordered_map<int,ListNode*>pref_sum;
        pref_sum[0]=start;
        while(curr){
            pref+=curr->val;
            if(pref_sum.find(pref)!=pref_sum.end()){
                ListNode* dels = pref_sum[pref]->next;
                int tempSum = pref+dels->val;
                while(dels!=curr){
                    pref_sum.erase(tempSum);
                    dels=dels->next;
                    tempSum+=dels->val;
                }
                pref_sum[pref]->next = curr->next;
                
            }
            else {
                pref_sum[pref]=curr;
            }
            curr=curr->next;
        }
        return start->next;

    }
};