/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/


class Solution {
  public:
  // TIME COMPLEXITY : O(N), SPACE COMPLEXITY: O(1).
    Node* deletehead(Node* head){
        
        // if(head == NULL) return NULL;
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev =NULL;
        }
        
        delete temp;
        return head;
    }
    
     Node* deletetail(Node* head){
        //  if(head == NULL) return NULL;
        
        Node* tail =head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail->prev = nullptr;
        delete tail;
        return head;
    }
    
  
    Node* delPos(Node* head, int x) {
        // code here
        // Empty list.
        if(head == NULL) return NULL;
        // Place curr to xth position.
        Node * curr = head;
        int cnt =0;
        while(curr != NULL){
            cnt ++;
            if(cnt == x) break;
            curr= curr->next;
        }
        Node* prevcurr = curr->prev;
        Node* frontcurr = curr->next;
        // If One node in list
        if(prevcurr == NULL && frontcurr == NULL){
            delete head;
            return NULL;
        }
        // delete first position.
        else if(prevcurr == NULL){
            return deletehead(head);
        }
        // delete tail.
        else if(frontcurr == NULL){
            return deletetail(head);
        }
        // delete Xth position which is the middle element in a list.
        else{
            prevcurr->next = frontcurr;
            frontcurr->prev = prevcurr;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
            return head;
        }
    }
};








