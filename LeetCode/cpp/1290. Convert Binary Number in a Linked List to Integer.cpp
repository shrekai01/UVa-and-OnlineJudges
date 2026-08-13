/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Linked List
    int getDecimalValue(ListNode* head) {
        ListNode *p = head;
        int ans = 0;
        while(p){
            ans = ans * 2 + p->val;
            p = p->next;
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is the length of the Linked List
};