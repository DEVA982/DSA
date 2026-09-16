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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return nullptr;
        if(size==1) return lists[0];
        priority_queue <pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i = 0 ; i<size ; i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next!=nullptr){
                pq.push({minNode->next->val,minNode->next});
            }
            temp->next=minNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};