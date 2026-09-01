/* Node Structure
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
// TIME COMPLEXITY : O(N), SPACE COMPLEXITY O(1).
    int getNode(Node* head, int k) {
        // code here
        if(head == NULL) return -1;
        
        Node * temp = head;
        int cnt =0;
        while(temp != NULL){
            cnt++;
            if(cnt == k){
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }
};
