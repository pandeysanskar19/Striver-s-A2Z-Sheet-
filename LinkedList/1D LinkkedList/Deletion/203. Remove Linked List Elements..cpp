// struct Node {
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

Node* removeKey(Node* head, int key) {
    //write code here...
    if(head == NULL) return head;
    
    while( head != NULL && head->data == key){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    Node* prev = head;
    Node * temp = head->next;
    while(temp != NULL){
        if(temp-> data == key){
            prev->next  = temp->next;
            delete temp;
            temp  = prev->next; 
        }
        else{
            prev =temp;
            temp = temp->next;
        }
    }
    return head;
}
