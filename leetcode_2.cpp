class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* last = dummyHead;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = carry;
            
            if(l1) {
                sum += l1->val;
                l1 = l1->next;  // Move inside l1 check
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;  // Move inside l2 check
            }
            
            last->next = new ListNode(sum % 10);
            carry = sum / 10;
            last = last->next;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
