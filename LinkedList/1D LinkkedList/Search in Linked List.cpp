/* Structure of Linked List Node
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
  
  // TIME COMPLEXITY: O(N) , SPACE COMPLEXITY: O(1).
    bool searchKey(Node* head, int key) {
        // Code here
        // don't tamper the head, so take one temporary variable.
        Node * temp = head;
        while(temp != NULL){
            if(temp->data == key) return true;
             temp = temp->next;
        }
        return false;
    }
};
