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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *tail = head;
        for(ListNode *cur = head->next; cur->next; cur = cur->next){
            if(cur->val){
                tail->val += cur->val;
            }
            else{
                tail = tail->next;
                tail->val = 0;
            }
        }
        tail->next = nullptr;
        return head;
    }
    // O(n) time, O(1) extra-space, where n is the length of the Linked List
};