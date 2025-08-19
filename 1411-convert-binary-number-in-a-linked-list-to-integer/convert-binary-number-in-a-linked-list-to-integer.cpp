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
    int getDecimalValue(ListNode* head) {

        if (!head) return 0;

        int idx = -1;

        ListNode* flow = head;
        while (flow){
            flow = flow->next;
            idx++;
        }

        flow = head;
        int result = 0;
        
        while(flow){
            result+= flow->val*(1<<idx--);
            flow = flow->next;
        }

        return result;
        
    }
};