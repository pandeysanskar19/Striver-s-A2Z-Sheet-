/* Structure of doubly linked list Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
//TIME COMPLEXITY:O(1) , SPACE COMPLEXITY:O(1).
    Node* deleteHead(Node* head) {
        // code here
        // List is empty or having one element.
        if(head == NULL || head->next == NULL) return NULL;
        // else
        Node* curr = head;
        head = head->next;
        head->prev = NULL;
        curr->next = NULL;
        return head;
    }
};
