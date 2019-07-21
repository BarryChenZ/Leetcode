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
    int counter = 0;
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size();
        if(n <= 1) return res;
        int i = 0;
        int temp = nums[0];
        int start = i;
        while(i < n){
            if(nums[i] == temp){
                counter++;
            
            }
            else{
                if(counter > 1){
                    for(int j = 0; j < counter; j++){
                        nums.erase(nums.begin() + start);
                        n--;
                    }
                    i = start;
                }
                temp = nums[i];
                start = i;
                counter = 1;
            }
            i++;
        }
        if(counter > 1){
            for(int j = 0; j < counter; j++){
                nums.erase(nums.begin() + start);
                n--;
            }
        }
        ListNode *tmp = new ListNode(nums[0]);
        res =  tmp;
        cout << n;
        for(int i = 0; i < n; i++){
            ListNode *tmp1 = new ListNode(nums[i]);
            tmp->next = tmp1;
            tmp = tmp->next;
        }
        return res->next;
    }
};
