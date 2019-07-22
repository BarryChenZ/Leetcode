/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = NULL;
        ListNode* cur2 = NULL;
        while(head){
            if(!cur){
                cur = head;
                cur2= head;  
            }
            else{
                cur2->next = head;
                cur2 = cur2->next;
            }
            int temp = head->val;
            if(head->next && temp == head->next->val){
                while(head->next && temp == head->next->val){
                    head = head->next;
                }
            }
            head = head->next;
        }
        if(cur2) cur2->next = NULL;
        return cur;
    }
};
