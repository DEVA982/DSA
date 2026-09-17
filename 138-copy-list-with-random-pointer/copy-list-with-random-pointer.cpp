/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr)
            return nullptr;

        Node* curr = head;

        // 1. Insert copied nodes
        while(curr != nullptr) {

            Node* copy = new Node (curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        // 2. Set random pointers
        Node* temp = head;

        while(temp != nullptr) {

            if(temp->random!=nullptr){
                temp->next->random=temp->random->next;
            }
            temp = temp->next->next;
        }

        // 3. Separate the two lists
        temp = head;
        Node* newHead = head->next;

        while(temp != nullptr) {

            Node* copy = temp->next;
            temp->next=copy->next;
            if(copy->next!=nullptr){
                copy->next = copy->next->next;
            }
            temp=temp->next;
        }

        return newHead;
    }
};