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

    ListNode* rotate(ListNode* head){
        ListNode* current=head;
        while(current->next){
            current=current->next;
        }
        ListNode* last=current;
        last->next=head;
        current=head;
        while(current->next!=last){
            current=current->next;
        }
        current->next=nullptr;
        return last;
    }



    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int count=1;
        ListNode* pakodi=head;
        while(pakodi->next){
            pakodi=pakodi->next;
            count++;
        }
        k=k%count;
        while(k--){
            head=rotate(head);
        }
        return head;
    }
};