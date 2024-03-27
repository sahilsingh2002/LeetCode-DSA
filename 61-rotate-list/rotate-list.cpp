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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size = 0;
        ListNode*nex=head;
        while(nex){
            size++;
            nex=nex->next;
        }

        k%=size;
        if(k==0) return head;
        int rem = size-k;
        nex =head;
        for(int i=0;i<rem-1;i++){
            nex=nex->next;
        }
        ListNode*newH = nex->next;
        nex->next=NULL;
        nex=newH;
        while(nex->next) nex=nex->next;
        nex->next=head;
        return newH;
    }
};