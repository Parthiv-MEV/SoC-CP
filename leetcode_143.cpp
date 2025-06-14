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
    vector<ListNode*> read(ListNode* head, int count){
        vector<ListNode*> vec(0, nullptr);
        vec.push_back(head);
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            vec.push_back(curr);
        }
        return vec;
    }
    void reorderList(ListNode* head) {
        int count=1;
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            count++;
        }
        vector<ListNode*> vec=read(head,count);
        for(int i=0; i<count;i++){
            int mid=count/2;
            ListNode* node=vec[i];
            if(i<mid){
                node->next=vec[count-1-i];
            }
            else if(i==mid){
                node->next=nullptr;
            }
            else{
                node->next=vec[count-i];
            }
        }

    }
};