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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        int count = 0;
        ListNode* temp = head;

        //check whether it is possible or not
        while (temp && count < k){
            temp = temp->next;
            count++;
        }

        // if not possible return here
        if (count != k) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;
        while (curr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;
            count++;
        }

        head->next = reverseKGroup( curr , k );

        return prev;
    }
};