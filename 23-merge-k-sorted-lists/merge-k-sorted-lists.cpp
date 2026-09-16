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
    ListNode* merge(ListNode* headA,ListNode* headB){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(headA!=nullptr && headB!=nullptr){
            if(headA->val<headB->val){
                temp->next=headA;
                headA=headA->next;
            }
            else{
                temp->next=headB;
                headB=headB->next;
            }
            temp=temp->next;
        }
        if(headA==nullptr){
            temp->next=headB;
        }
        else{
            temp->next=headA;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return nullptr;
        if(size==1) return lists[0];
        ListNode* right = lists[0];
        for(int i = 1 ; i<size ; i++){
            right = merge(right,lists[i]);
        }
        return right;
    }
};