class Solution {
public:
    ListNode* reverseGroup(ListNode* head, int size) {
        if (!head) return nullptr;

        // Count actual nodes in this group
        ListNode* temp = head;
        int count = 0;
        while (temp && count < size) {
            temp = temp->next;
            count++;
        }

        
        if (count % 2 == 0) {
            ListNode* curr = head;
            ListNode* prev = temp;
            for (int i = 0; i < count; i++) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            head->next = reverseGroup(temp, size + 1);
            return prev;
        } else {
            
            ListNode* curr = head;
            for (int i = 1; i < count; i++) {
                curr = curr->next;
            }
            curr->next = reverseGroup(temp, size + 1);
            return head;
        }
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return reverseGroup(head, 1);
    }
};
