/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
// TIME COMPLEXITY : O(n) , SPACE COMPLEXITY : O(1).
    int getCount(Node* head) {
        // Code here
        int length =0;
        Node * temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
};
