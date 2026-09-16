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

    ListNode* kthNode(ListNode* temphead, int k){
        int count =1;
        ListNode* temp=temphead;
        while(temp!=nullptr){
            if(count == k){
                
                return temp;
            }
            temp=temp->next;
            count++;
        }
        return nullptr;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevGroup = nullptr;
        while(temp!=nullptr){
            ListNode* Knode = kthNode(temp,k);
            if(Knode==nullptr){
                break;
            }
            ListNode* futureNode = Knode->next;
            
            
            ListNode* curr = temp;
            ListNode* prev=futureNode;
            while(curr!=futureNode){
                ListNode* next1 = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next1;
            }
            if(prevGroup==nullptr){
                head=Knode;
            }
            else{
                prevGroup->next=Knode;
            }
            prevGroup=temp;
            temp=futureNode;

        }
        return head;
    }
};