/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution1 {
  public:
  
  // TIME COMPLEXITY :O(N) , SPACE COMPLEXITY (STACK): O(N).
    Node *reverse(Node *head) {
        // code here
        if(head == nullptr || head->next == nullptr) return head;
        Node* temp = head;
        // to store all node data.
        stack<int>st;
        // store node data :
        while(temp != nullptr){
            st.push(temp->data);
            temp = temp->next;
        }
        //Reintialise:
        temp =head;
        // pop data back to node in reverse order. 
        while(temp != nullptr){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};


class Solution2 {
  public:
  //    TIME COMPLEXITY :O(N) , SPACE COMPLEXITY: O(1).
  
    Node *reverse(Node *head) {
        // code here
        // when list is empty or there is only one node in the list.
        if(head == nullptr || head->next == nullptr) return head;
        // else :
        Node * curr = head;
        Node* back = NULL;
        // swap the next and prev pointer for all nodes in the list
        while(curr != nullptr){
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;
            // move curr to curr->next node(which is now curr->prev because of swap)
            curr = curr->prev;
        }
        return back->prev;
    }
};
