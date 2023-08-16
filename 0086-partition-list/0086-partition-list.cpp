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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = new ListNode(1000);
        ListNode *second = new ListNode(1000);
        ListNode *first_cur = first, *second_cur = second;
        while(head) {
            if(head->val >= x) {
                second_cur->next = head;
                second_cur = head;
            } else {
                first_cur->next = head;
                first_cur = head;
            }
            head = head->next;
        }
        
        second_cur->next = nullptr;
        first_cur->next = second->next;

        // return first;
        return first->next;
    }
};