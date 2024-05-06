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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>valid;
        ListNode*temp = head;
        while(temp!=NULL){
            while(!valid.empty() && temp->val>valid.top()->val){
                ListNode*x = valid.top();
                cout<<x->val<<endl;
                valid.pop();
                delete x;
            }
            valid.push(temp);
            temp=temp->next;
        }
        ListNode*main = new ListNode(0);
        while(!valid.empty()){
            ListNode*x = valid.top();
            valid.pop();
            x->next = main;
            main = x;
        }
        temp = main;
        ListNode*prev = main;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next =NULL;
        delete temp;
        return main;
        
        // return head;
    }
};