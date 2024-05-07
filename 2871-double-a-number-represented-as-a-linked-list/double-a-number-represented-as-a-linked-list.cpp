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
 #define ll long long
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
       
        ListNode*temp = head;
        vector<int>nums;
        nums.push_back(0);
        while(temp!=nullptr){
           
            nums.push_back(temp->val);
            temp = temp->next;
        }
       int n = nums.size()-1;
       int over = 0;
       while(n>=0){
        int p = nums[n]*2;
        p+=over;
        // cout<<p<<endl;
        if(p>=10){
           over = p/10;
           p = p%10;
        }
        else{
            over = 0;
        }
        nums[n]=p;
        n--;
       }
        int idx = 0;
        temp = head;
        if(nums[0]==0){
            idx++;
        }
        ListNode*prev = head;
        while(temp!=nullptr){

            prev = temp;
            temp->val = nums[idx];
            idx++;
            temp=temp->next;
        }
        while(idx<nums.size()){
            ListNode* x = new ListNode(nums[idx]);
            prev->next= x;
            prev = prev->next;
            idx++;
        }
        return head;
    }

};