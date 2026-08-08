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
    // monotonic stack, Linked List
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> st;
        int index = 0;
        while(head){
            while(!st.empty() && head->val > st.top().second){
                res[st.top().first] = head->val;
                st.pop();
            }
            st.push({index, head->val});
            
            index++;
            head = head->next;
            res.push_back(0);
        }
        return res;
    }
    // O(n) time, O(n) extra-space
};