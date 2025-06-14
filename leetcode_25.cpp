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
    vector<ListNode*> read(ListNode* head, int& count){
            vector<ListNode*> vec(0, nullptr);
            vec.push_back(head);
            ListNode* curr=head;
            while(curr->next){
                curr=curr->next;
                vec.push_back(curr);
                count++;
            }
            return vec;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=1;
        vector<ListNode*> v=read(head,count);
        for(int i=0; (i+1)*k<count+1;i++){
            reverse(v.begin()+i*k,v.begin()+i*k+k);
        }
        head=v[0];
        for(int i=0; i<count; i++){
            ListNode* node=v[i];
            if(count-1==i){
                node->next=nullptr;
                break;
            }
            node->next=v[i+1];
        }
        return head;
    }
};