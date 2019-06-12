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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *result = NULL;
        //check size
        ListNode *p = head;
        int size = 0;
        while (p != NULL){ 
            ++size; 
            p = p->next; 
        }
        if(size == 1) return result;
        p = head;
        //before target
        ListNode *temp;
        for(int i = 0; i < size - n - 1; ++i){\
            p = p->next;
        }
        if(size - n == 0){
            result = p->next;
            return result;
        }
        p->next = p->next->next;
        result = head;
        return result;
    }
};
