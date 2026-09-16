/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        Node* tail = head;
        while(tail->next!=nullptr){
            tail = tail->next;
        }
        if(tail==head){
            return head;
        }
        for(int i = 0 ; i<k ; i++){
            Node* temp = head;
            head = head->next;
            tail->next = temp;
            tail=temp;
            tail->next=nullptr;
        }
        return head;
    }
};