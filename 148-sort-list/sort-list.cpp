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
    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(left!=nullptr && right!=nullptr){
            if(left->val<right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left==nullptr){
            temp->next=right;
        }
        else{
            temp->next=left;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* right = slow->next;
        slow->next=nullptr;
        ListNode* left = sortList(head);
        right = sortList(right);
        return merge(left,right);
    }
};