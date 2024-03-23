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
 ListNode* reverse (ListNode* head){
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
        return curr;
 }
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode*slow = head, *fast = head, *prev;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast==slow) return;
        prev->next = NULL;
        ListNode*temp = slow->next;
        slow->next = NULL;
        ListNode* l1 = reverse(temp);
        temp = head;
        while(temp!=NULL && l1!=NULL){
            ListNode*curr = temp->next;
            temp->next = l1;
            l1=l1->next;
            temp=temp->next;
            temp->next = curr;
            temp=temp->next;
        }
        temp = head;
        while(temp!=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = slow;

        
        
        
    }
};