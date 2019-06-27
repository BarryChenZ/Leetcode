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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        vector<int> A;
        while(head){
            A.push_back(head->val);
            head = head->next;
        }
        int n = A.size();
        for(int i = 0; i < n; i++){
            if(i + 1 < n){
                int x = A[i+1];
                A[i+1] = A[i];
                A[i] = x;
                ListNode* tmp = new ListNode(A[i]);
                temp->next = tmp;
                temp = temp->next;
                ListNode* tmp1 = new ListNode(A[i+1]);
                temp->next = tmp1;
                temp = temp->next;
                i++;
            }
            else{
                int x = A[i];
                ListNode* tmp = new ListNode(A[i]);
                temp->next = tmp;
                temp = temp->next;
            }
        }
        return result->next;
    }
};
