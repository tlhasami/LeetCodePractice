/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* bfs(Node* head){

        Node* temp = head;
        Node* prev = nullptr;


        while (temp){
            if (temp->child){
                Node* next = temp->next;
                Node* last = bfs(temp->child);

                temp->next = temp->child;
                temp->child->prev = temp;
                last->next = next;
                if (next)
                    next->prev = last;

                temp->child = nullptr;
            }

            prev = temp;
            temp = temp->next;
        }

        return prev ;
    }
    Node* flatten(Node* head) {
        Node* last = bfs(head);

        return head;
    }
};