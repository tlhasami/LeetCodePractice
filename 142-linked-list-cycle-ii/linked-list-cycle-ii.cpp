/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int>addresses;

        ListNode* temp = head;
        while (temp){
            if (addresses.find(temp) != addresses.end()){
                return temp;
            }
            addresses[temp] ++;
            temp = temp->next;
        }


        return nullptr;
    }
};