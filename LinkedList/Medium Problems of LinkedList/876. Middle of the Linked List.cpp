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
// TIME COMPLEXITY : O(N), SPACE COMPLEXITY : O(1).
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        vector<ListNode*> ans;
// slow and fast pointer technique : when fast is at the last then slow is at middle.
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};


class Solution2 {
public:
// TIME COMPLEXITY : O(N)+O(N/2) = O(N), SPACE COMPLEXITY : O(1).
    ListNode* middleNode(ListNode* head) {
        ListNode* currentNode = head;
        int length =0;
        // calculate the length.
        while(currentNode != nullptr){
            length ++;
            currentNode = currentNode->next;
        }
        int middle_node = 0;
        middle_node =length/2 +1;

        currentNode = head;int found =0;
        // find the middle node.
        while(currentNode != nullptr){
            found++;
            if(found == middle_node){
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr; 
    }
};
