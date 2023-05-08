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
    ListNode* middleNode(ListNode* head) {
        /** Method Used here is Slow and Fast pointer.
         * first pointer is slow pointer and second pointer is fast pointer.
         */
        
        
        ListNode *first = head, *second = head;
        while(second != nullptr && second->next != nullptr) {
            cout << first->val << " " << second->val << endl;
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};