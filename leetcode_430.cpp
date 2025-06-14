class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* childHead = flatten(curr->child); 
                Node* next = curr->next;

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
