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
    ListNode* reverseList(ListNode* head) {
        ListNode*prev = head;
        ListNode*curr = head;
        if(head==NULL || head->next == NULL) return head;
        ListNode*nex = head->next;
        prev->next = NULL;
        while(nex!=NULL){
            curr=nex;
            nex = nex->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};