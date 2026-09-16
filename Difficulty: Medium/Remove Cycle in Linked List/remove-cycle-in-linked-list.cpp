/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        bool isCycle=false;
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        if(isCycle){
            slow=head;
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
        }
        else{
            return;
        }
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=nullptr;
        //return head;
        
    }
};