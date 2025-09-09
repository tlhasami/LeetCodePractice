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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* firstIdx = head, *lastIdx = head;
        int size = 0;
        
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            size++;
        }

        int idx = 1;
        while(firstIdx){
            if (idx == k){
                break;
            } 

            firstIdx = firstIdx->next;
            idx++;
        }

        idx = 1;
        while(lastIdx){
            if (idx == size - k + 1){
                break;
            } 

            lastIdx = lastIdx->next;
            idx++;
        }

        int value = firstIdx->val;
        firstIdx->val = lastIdx->val;
        lastIdx->val = value;


        return head;
       
    }
};



       /*

        ListNode* temp = head;
        int count = 1;
        while (temp){
            cout << count << " " << temp->val << endl;

            if (count%k == 0 && temp->next){
                ListNode* nextMovement = temp->next;
                count++;
                while (nextMovement){
                    cout << count << " " << nextMovement->val << endl;
                    if (count%k == 0){
                        int value = temp->val;
                        temp->val = nextMovement->val;
                        nextMovement->val = value;
                        break;
                    }
                    count++;
                    nextMovement = nextMovement->next;
                }

                temp = nextMovement->next;

            } else {
                count++;
                temp = temp->next;
            }


        }

        return head;

       */     