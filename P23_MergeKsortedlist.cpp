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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result=new ListNode(0);
        ListNode* temp=result;
        
        vector<int> A;
 
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                A.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        for(int i = 0; i < A.size(); i++){
            for(int j = i; j < A.size(); j++){
                if(A[i]>A[j]){
                    int temp=A[j];
                    A[j] = A[i];
                    A[i] = temp;
                }
            }
            ListNode* tmp = new ListNode(A[i]);
            temp->next=tmp;
            temp = temp->next;
        }
        
        return result->next;
    }
};
