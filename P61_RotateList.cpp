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
    ListNode* rotateRight(ListNode* head, int k) {
        int num = 0;
        ListNode* res;
        ListNode* temp = head;
        while(temp != NULL){
            num++;
            temp = temp->next;
        }
        if(num <= 1) return head;
        int steps = k%num;
        if(steps == 0) return head;
        steps = num - steps;
        temp = head;//舊的頭
        ListNode* temp1;
        for(int i = 0; i < num - 1; i++){
            if(i == steps - 1){
                temp1 = head;//新的尾
                head  = head->next;
                res = head;//新的頭
            }
            else{
                head  = head->next;
            }
        }
        temp1->next = NULL;
        head->next = temp;
        return res;
    }
};
