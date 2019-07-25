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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int counter = 1;
        ListNode* res = head;
        if(m == n) return res;
        while(head){//找m前一位
            if(counter == m - 1 || m == 1){
                break;
            }
            head = head->next;
            counter++;
        }
        ListNode* top = head;
        ListNode* mid = top->next;
        //頭用D2
        ListNode* down= mid->next;
        ListNode* down2 = top;
        for(int i = m; i < n; i++){
            down = mid->next;
            if(m == 1){
                ListNode* temp = mid->next;
                mid->next = top;
                down2->next = temp;
                top = mid;
                mid = down2->next;
                res = top;
            }
            else{
                ListNode* temp = top->next;
                top->next = down;
                mid->next = down->next;
                down->next = temp;
            }
        }
        return res;
    }
};
