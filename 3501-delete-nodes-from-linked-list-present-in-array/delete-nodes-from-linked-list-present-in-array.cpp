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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_map<int,int>values;

        for (int& num:nums)
            values[num] = 1;
        ListNode* start = new ListNode(0);
        start->next = head;

        ListNode* temp = start;
        while (temp->next){
            if (values.find(temp->next->val) != values.end()){
                temp->next = temp->next->next;
                continue;
            }

            temp = temp->next;
        }

        return start->next;
    }
};