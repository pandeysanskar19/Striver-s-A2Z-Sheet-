/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
//TIME COMPLEXITY:O(1), SPACE COMPLEXITY :O(1).
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node* temp = new Node(x);
        temp->next = head;
        return temp;
    }
};
