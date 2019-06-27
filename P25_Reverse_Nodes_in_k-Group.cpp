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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        vector<int> A;
        while(head){
            A.push_back(head->val);
            head = head->next;
        }
        int n = A.size();
        for(int i = 0; i < n; i++){
            if(i + k-1 < n){
                int front = i;
                int end = i+k-1;
                while(front < end){
                    int x = A[end];
                    A[end] = A[front];
                    A[front] = x;
                    front ++;
                    end --;
                }
                for(int j = i; j < i+k; ++j){
                    ListNode* tmp = new ListNode(A[j]);
                    temp->next = tmp;
                    temp = temp->next;
                }
                i += k-1;
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
