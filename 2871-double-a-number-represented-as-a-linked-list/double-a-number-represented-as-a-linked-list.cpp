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
    ListNode* doubleIt(ListNode* head) {
        vector<int> values;

        ListNode* temp = head;
        while(temp){
            values.push_back(temp->val);
            temp = temp->next;
        }

        //reverse(values.begin(), values.end());
        int carry = 0 , n = values.size() , number = 0;

        for (int i = n - 1 ; i >= 0 ; i--){

            number = values[i]*2 + carry;
            carry = number/10 ;
            number = number%10;

            values[i] = number;

        }

        if (carry > 0){
            ListNode* toAdd = new ListNode(carry);
            toAdd->next = head;
            temp = head;
            head = toAdd;
        } else {
            temp = head;
        }

        for (int i = 0 ; i < n ; i++){
            temp->val = values[i];
            temp = temp->next;
        }

        return head;

        

    }
};