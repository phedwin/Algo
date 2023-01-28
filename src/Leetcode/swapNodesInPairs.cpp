/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
*/

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
        // Edge case: empty or single-node list
        if (!head || !head->next) {
            return head;
        }
        // Create dummy node for easy handling of head node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (head && head->next) {
            ListNode* second = head->next;
            head->next = second->next;
            second->next = head;
            prev->next = second;
            prev = head;
            head = head->next;
        }
        return dummy.next;
    }
};
