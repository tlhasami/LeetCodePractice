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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* first = nullptr, * last;

        int idx = 0;
        while (temp){
            if (idx == a-1){
                first = temp;
            } else if (idx == b+1){
                last = temp;
                break;
            } 
            temp = temp->next;
            idx++;
        }

        temp = list2;
        while(temp->next){
            temp = temp->next;
        }

        first->next = list2;
        temp->next = last;

        return list1;

        
    }
};