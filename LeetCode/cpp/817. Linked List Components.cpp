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
    // Linked List, hash table
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int ans = 0;
        for(ListNode *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next){
            if((!prev || !ust.contains(prev->val)) && ust.contains(cur->val)) ans++;
        }
        return ans;
    }
    // O(n) time, O(m) extra-space, where n is the length of the Linked List and m is nums.length
};