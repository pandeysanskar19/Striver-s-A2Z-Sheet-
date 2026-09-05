/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution1 {
public:
// time complexity: o(n) , space complexity:o(n).
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        unordered_map<ListNode *,bool> visited;
        ListNode* temp = head;
        while(temp != NULL){
            if(visited.find(temp) != visited.end()) return true;
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};

class Solution2 {
public:
// TIME COMPLEXITY :O(N), SPACE COMPLEXITY :O(1).
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
             slow = slow->next;
            fast = fast->next->next;
            if(fast == slow ) return true;
        } 
        return false;
    }
};
