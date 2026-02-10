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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* cur=ans;
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        int sum=0,carry=0;
        while(cur1!=nullptr && cur2!=nullptr){
            sum=cur1->val+cur2->val+carry;
            carry=sum/10;
            sum%=10;
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        while(cur1!=nullptr && cur2==nullptr){
            sum=cur1->val+carry;
            carry=sum/10;
            sum%=10;
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur1=cur1->next;
        }
        while(cur1==nullptr && cur2!=nullptr){
            sum=cur2->val+carry;
            carry=sum/10;
            sum%=10;
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur2=cur2->next;
        }
        if(carry!=0){
            sum=carry;
            carry=sum/10;
            sum%=10;
            cur->next=new ListNode(sum);
        }
        return ans->next;
    }
};