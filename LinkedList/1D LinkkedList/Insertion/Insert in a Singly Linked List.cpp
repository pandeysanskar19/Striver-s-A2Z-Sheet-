/* Structure of Linked List Node
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
// TIME COMPLEXITY : O(N) , SPACE COMPLEXITY: O(1).
    Node* insertPos(Node* head, int pos, int val) {
        // code here
        //list is empty.
        if(head == NULL) {
            if(pos == 1) return new Node(val);
            return NULL;
        }
        // Insert at 1st position
        if(pos == 1){
            Node * temp = new Node(val);
            temp->next = head;
            return temp;
        }
        
        // Insert at pos(kth) position.
        if(pos>1){
            int cnt =0; Node* temp = head;
            while(temp != NULL){
                cnt++;
                if(cnt == pos-1){
                    Node* insert = new Node(val);
                    insert->next = temp->next;
                    temp->next = insert;
                    break;
                }
                temp = temp->next;
            }
        }
        return head;
    }
};
