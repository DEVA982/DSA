/* Structure of a Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        //lets fi
        if(a==b) return head;
        Node* ptra = head;
        Node* prev = nullptr;
        int ptracount = 1;
        while(ptracount<a){
            prev = ptra;
            ptra=ptra->next;
            ptracount++;
        }
        Node* ptrb = ptra;
        int ptrbcount = ptracount;
        while(ptrbcount<b){
            ptrb=ptrb->next;
            ptrbcount++;
        }
        Node* future = ptrb->next;
        Node* prevNode = future;
        Node* curr = ptra;
        while(curr!=future){
            Node* next1 = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr= next1;
        }
        if(ptra==head){
            head=ptrb;
        }
        else{
            prev->next=ptrb;
        }
        return head;
        
        
        
    }
};