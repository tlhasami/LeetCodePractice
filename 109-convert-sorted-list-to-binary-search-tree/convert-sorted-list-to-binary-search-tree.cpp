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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* current;
    int getCount(ListNode* head){
        if (!head) return 0;

        int count = 0;
        while (head){
            count++;
            head = head->next;
        }

        return count;
    }

    TreeNode* built(int low , int high){
        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;
        
        TreeNode* left = built(low , mid-1);
        TreeNode* root = new TreeNode(current->val);
        current = current->next;
        TreeNode* right = built(mid+1 , high);

        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getCount(head);
        current = head;
        return built(1,n);
    }

    /*
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        if (prev) 
            prev->next = nullptr;
        
        root->left = sortedListToBST(head == slow ? nullptr : head);
        root->right = sortedListToBST(slow->next);

        return root;

    }

    */
};