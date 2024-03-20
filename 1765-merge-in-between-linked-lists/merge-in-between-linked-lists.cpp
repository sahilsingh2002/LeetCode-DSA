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
        ListNode*prev = list1;
        ListNode*temp = list1;
        int x=0;
        while(x<a){
            prev=temp;
            temp=temp->next;
            x++;
        }
        prev->next=list2;
        ListNode*preprev = prev;
        while(prev!=NULL){
            preprev = prev;
            prev=prev->next;
        }
        prev=temp;
        while(x<=b ){
            prev=temp;
            temp=temp->next;
            delete prev;
            x++;
        }
        if(temp!=NULL){
            preprev->next = temp;
        }
        return list1;
    }
};