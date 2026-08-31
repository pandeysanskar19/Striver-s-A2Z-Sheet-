/*
class Node {
public:
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
// TIME COMPLEXITY :O(N) , SPACE COMPLEXITY : O(1).
    Node* removeLastNode(Node* head) {
        // code here
        // List is empty or have one element return null.
        if(head == NULL || head->next == NULL) return NULL;
        Node * temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        // free the last node.
        free(temp->next);
        temp->next = nullptr;
        return head;
    }
};
