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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto list : lists){
            ListNode* temp = list;

            while (temp){
                minHeap.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* result = new ListNode(0);
        ListNode* temp = result;

        while (!minHeap.empty()){
            ListNode* toAdd = new ListNode(minHeap.top());
            minHeap.pop();
            temp->next = toAdd;
            temp = toAdd;
        }

        return result->next;
    }
};