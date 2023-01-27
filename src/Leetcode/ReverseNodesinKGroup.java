package Leetcode;


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

public class ReverseNodesinKGroup {

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode start = dummy;
        int count = 0;
        while (head != null) {
            count++;
            if (count % k == 0) {
                start = reverse(start, head.next);
                head = start.next;
            } else {
                head = head.next;
            }
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode start, ListNode end) {
        ListNode curr = start.next;
        ListNode prev = start;
        ListNode first = curr;
        while (curr != end) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        start.next = prev;
        first.next = curr;
        return first;
    }
}
