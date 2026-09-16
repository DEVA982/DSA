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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return ;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;

        }
        ListNode* middle = slow->next;
        slow->next=nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = middle;
        while(curr!=nullptr){
            ListNode* next1 = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
        }
        ListNode* right =prev;
        ListNode* left = head;
        while(left!=nullptr && right!=nullptr){
            ListNode* l1=left->next;
            ListNode* r1 = right->next;
            left->next = right;
            right->next = l1;
            left=l1;
            right=r1;
        }
        //if(left!=nullptr) right->next= left;
        

        
    }
};