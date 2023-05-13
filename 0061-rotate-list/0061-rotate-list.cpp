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
        int count = 1;
        while(tail->next != nullptr) {
            count += 1;
            tail = tail->next;
        }
        // cout << count << " " << tail->val << endl;
        tail->next = head;
        k = k%count;
        k = count - k;
        while(k--) {
            tail=tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
            
        return head;
    }
};