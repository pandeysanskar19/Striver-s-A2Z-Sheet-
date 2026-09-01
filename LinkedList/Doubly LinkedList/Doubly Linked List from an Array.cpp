/* class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
  //Time Complexity: O(n)  Auxiliary Space: O(1).
    Node* createDLL(vector<int>& arr) {
        // code here
        // create head node .
        Node * head = new Node(arr[0]);
        // create dummy node , intially at head.
        Node * dummy = head;
        
        for(int i=1;i<arr.size();i++){
            Node * temp =new Node(arr[i]);
            dummy->next = temp;
            temp->prev = dummy;
            dummy = temp;
        }
        return head;
    }
};
