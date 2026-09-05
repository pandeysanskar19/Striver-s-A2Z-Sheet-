/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution1 {
public:
// TIME COMPLEXITY: O(N) , SPACE COMPLEXITY: O(N)
    ListNode* reverseList(ListNode* head) {
        ListNode* currentNode = head;
        stack<int>Elementstack;
        while(currentNode != nullptr){
            Elementstack.push(currentNode->val);
            currentNode = currentNode->next;
        }

        currentNode =head;
        while(currentNode != nullptr){
            currentNode->val = Elementstack.top();
            Elementstack.pop();
            currentNode = currentNode->next;
        }
        return head;
    }
};

class Solution2 {
public:
// TIME COMPLEXITY: O(N) , SPACE COMPLEXITY: O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* currentNode = head;
        ListNode* back = NULL;
        ListNode* front = NULL;
        while(currentNode != NULL){
            front = currentNode->next;
            currentNode->next = back;
            back = currentNode;
            currentNode = front;
        }
        return back;  
    }
};


class Solution3 {
public:
// TIME COMPLEXITY: O(N) , SPACE COMPLEXITY: O(N)
    ListNode* reverseList(ListNode* head) {
        // for empty list and one node in a list.
        if(head == nullptr || head->next == nullptr) return head;
        //recursively reverse the list.
        ListNode* newnode = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newnode;
    }  
};
