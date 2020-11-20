/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode Res = new ListNode(0);
        ListNode Ans = Res;
        int added = 0;
        while(l1 != null || l2 != null || added != 0){
            int temp = 0;
            if(l1 != null) {
                temp += l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                temp += l2.val;
                l2 = l2.next;
            }
            temp += added;
            if(temp >= 10){
                added = 1;
                temp %= 10;
            }
            else added = 0;
            ListNode newNode = new ListNode(temp);
            Res.next = newNode;
            Res = Res.next;
        }
        return Ans.next;
    }
}
