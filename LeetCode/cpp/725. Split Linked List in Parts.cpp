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
    int getListSize(ListNode *head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getListSize(head);
        ListNode *cur = head;
        vector<ListNode *> res(k);
        for(int i = 0; i < k; i++){
            int cnt = n / k + (i < n % k);
            res[i] = cur;
            for(int step = 0; step < cnt; step++){
                if(step == cnt - 1){
                    ListNode *next = cur->next;
                    cur->next = nullptr;
                    cur = next;
                }
                else cur = cur->next;
            }
        }
        return res;
    }
    // O(n) time, O(1) extra-space, where n is the length of the Linked List
};