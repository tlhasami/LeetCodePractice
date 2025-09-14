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

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;  // no need to reassign head separately
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        
        int carry = 0;
        while (l1 || l2){
            
            int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = val / 10;
            val %= 10;

            ListNode* toAdd = new ListNode(val);
            temp->next = toAdd;
            temp = toAdd;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }


        if (carry > 0){
            ListNode* toAdd = new ListNode(carry);
            temp->next = toAdd;
            temp = toAdd;
        }

        result = result->next;  
        result = reverse(result);

        return result;  
    }
};
