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

// TIME COMPLEXITY: O(1), SPACE COMPLEXITY : O(1).
    Node *deleteHead(Node *head) {
        // code here
        if(head == NULL) return head;
        Node * temp =head;
        head = temp->next;
        free(temp);
        return head;
    }
};
