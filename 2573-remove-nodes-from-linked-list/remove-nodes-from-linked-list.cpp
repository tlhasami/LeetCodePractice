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
        stack<ListNode*>st;
        ListNode* temp = head;

        while (temp){
            while(!st.empty() && st.top()->val < temp->val){
                st.pop();
            }

            st.push(temp);
            temp = temp->next;
        }

        ListNode* newList = nullptr;
        while (!st.empty()){
            ListNode* toAdd = st.top(); st.pop();
            toAdd->next = newList;
            newList = toAdd;
        }

        return newList;

        /*
        head = reverse(head);

        int currMax = head->val;
        ListNode* temp = head;
        while(temp->next){

            if (temp->next->val < currMax){
                temp->next = temp->next->next;
            } else {
                currMax = temp->next->val;
                temp = temp->next;
            }
                
            
        }

        head = reverse(head);
        return head;
        */
    }
};