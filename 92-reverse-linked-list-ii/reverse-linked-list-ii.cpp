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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        int count = 1;
        ListNode* curr = head;
        ListNode* beforeStart = nullptr;     

        // Step 1: move 'curr' to position 'left'
        while (count < left) {                  
            beforeStart = curr;              
            curr = curr->next;
            count++;
        }

        ListNode* start = curr;                 // start of reversal
        ListNode* prev = nullptr;

        // Step 2: reverse between left and right
        while (curr && count <= right) {        
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: reconnect reversed segment
        if (beforeStart) beforeStart->next = prev;  
        else head = prev;                           

        start->next = curr;                         

        return head;                                
    }
};
