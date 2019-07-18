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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        //check size
        ListNode *p;
        int L1size = 0;
        int L2size = 0;
        p = l1;
        while (p != NULL){ 
            ++L1size; 
            p = p->next; 
        }
        p = l2;
        while (p != NULL){
            ++L2size;
            p = p->next;
        }
    
        if(L1size == NULL && L2size == NULL) return result;
        if(L1size == NULL){
           return l2;
        }
        if(L2size == NULL){
           return l1; 
        }
        ListNode *temp = NULL;
        int a = 0;
        int b = 0;
        a = l1->val;
        b = l2->val;
        if(a >= b) {
            result = l2;
            l2 = l2->next;
            temp = result;
        }
        else{
            result = l1;
            l1 = l1->next;
            temp = result;
        }
        while(l1 != NULL && l2 != NULL){
            a = l1->val;
            b = l2->val;
            if(a >= b){
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
            else{
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
        }
        if(l1 == NULL){
           result->next = l2;
        }
        else{
           result->next = l1; 
        }
        /*
        for(int i = 0; i < L1size + L2size-1; ++i){
            if(l1 != NULL && l2 != NULL && a >= b){
                a = l1->val;
                b = l2->val;
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 != NULL && a < b){
                a = l1->val;
                
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
            else if(l1 == NULL){
                b = l2->val;
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
            else{ //l2 == NULL
                a = l1->val;
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
        }
        */
        result = temp;
        return result;
    }
};
