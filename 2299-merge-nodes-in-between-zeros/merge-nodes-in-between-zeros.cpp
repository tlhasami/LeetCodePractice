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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* ResultHead = new ListNode(0);
        ListNode* tail = ResultHead;
        
        ListNode* temp = head->next;
        int sum = 0;
        while(temp){
            if (temp->val == 0){
                ListNode* toAdd = new ListNode(sum);
                tail->next = toAdd;
                tail = toAdd;
                sum = 0;
            } else {
                sum += temp->val;
            }

            temp = temp->next;
        }

        return ResultHead->next;

    }
};