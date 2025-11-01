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
        ListNode* prev = nullptr , *curr = head;
        while (curr){
            ListNode* next = curr->next;
            curr->next=prev;
            prev = curr;

            curr = next;
        }

        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        stack<int>st;
        int currMax = head->val;
        ListNode* temp = head;
        while(temp->next){

            if (temp->next->val < currMax){
                temp->next = temp->next->next;
            } else {
                currMax = temp->next->val;
                temp = temp->next;
            }
                
                
            // while(!st.empty() && st.top() < temp->next->val){
            //     st.pop();
            //     st.push(temp->next->val);
            // }


            // if (st.top() > temp->next->val){
            //     temp->next = temp->next->next;
            //     continue;
            // }

            //temp = temp->next;
        }

        head = reverse(head);
        return head;
    }
};