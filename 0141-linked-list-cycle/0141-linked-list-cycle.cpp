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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mp;
        ListNode* node = head;
        while(node) {
            if(mp.count(node)) return true;
            mp[node] = 1;
            node = node->next;
        }
        return false;
    }
};