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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *cur = head->next, *next = head->next->next;
        int first_idx = -1, last_idx = -1, min_dist = INT_MAX;
        for(int i = 0; next; i++){
            if( (cur->val > prev->val && cur->val > next->val) ||
                (cur->val < prev->val && cur->val < next->val)){
                if(first_idx == -1) first_idx = i;             
                if(last_idx != -1 && i - last_idx < min_dist) min_dist = i - last_idx;
                last_idx = i;
            }
            prev = cur; cur = cur->next; next = cur->next;
        }
        if(first_idx == last_idx) return {-1, -1}; // fewer than 2 critical points
        return {min_dist, last_idx - first_idx};
    }
    // O(n) time, O(1) extra-space, where n is the length of the Linked List
};