/* Linked List Node Structure
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        Node* fast=head;
        Node* slow = head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
            //fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};