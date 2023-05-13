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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* tail = head;
        int count = 0;
        while(tail) {
            count += 1;
            tail = tail->next;
        }
        tail = head;
        k = k%count;
        while(k--) {
            while(tail->next->next) tail = tail->next;
            // cout << head->val << " "<< tail->val << endl;
            tail->next->next =  head;
            head = tail->next;
            tail->next = nullptr;
            tail = head;
        }
        return tail;
    }
};