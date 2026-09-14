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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        
        ListNode* ptr1 = head;
        for(int i = 0;i<n ;i++){
            ptr1=ptr1->next;
        }
        if(ptr1==nullptr){
            return head->next;
        }
       
        ListNode* ptr2 = head;
        while(ptr1->next!=nullptr){
            ptr1 = ptr1->next;
            ptr2=ptr2->next;
        }
        cout<<ptr2->val;
        ptr2->next=ptr2->next->next;
        return head;      
    }
};