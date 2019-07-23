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
    ListNode* partition(ListNode* head, int x) {
        ListNode* maxcur = NULL;
        ListNode* maxcur2 = NULL;
        ListNode* mincur = NULL;
        ListNode* mincur2 = NULL;
        if(!head || !head->next) return head;
        while(head){
            if(head->val >= x){
                if(!maxcur){
                    maxcur = head;
                    maxcur2 = head;
                }
                else{
                    maxcur2->next = head;
                    maxcur2 = maxcur2->next;
                }
            }
            else{
                if(!mincur){
                    mincur = head;
                    mincur2 = head;
                }
                else{
                    mincur2->next = head;
                    mincur2 = mincur2->next;
                }
            }
            head = head->next;
        }
        ListNode* res = NULL;
        if(mincur){
            res = mincur;
            mincur2->next = maxcur;
        }
        else{
            res = maxcur;
        }
        if(maxcur2) maxcur2->next = NULL;
        return res;
    }
};
