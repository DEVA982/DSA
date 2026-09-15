/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head->next==nullptr) return head;
        Node* newHead=nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            Node* last = curr->prev;
            curr->prev=curr->next;
            curr->next=last;
            newHead=curr;
            curr=curr->prev;
        }
        return newHead;
    }
};