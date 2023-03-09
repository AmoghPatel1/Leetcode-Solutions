/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> s;
        ListNode* cur = head;
        while(cur) {
            if(s.find(cur) != s.end()) {
                return cur;
            }
            s.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};