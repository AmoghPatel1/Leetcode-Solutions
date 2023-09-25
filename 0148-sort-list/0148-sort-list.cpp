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
    ListNode* sortList(ListNode* head) {
        ListNode* node = head;
        vector<int> v;
        while(node) {
            v.push_back(node->val);
            node = node->next;
        }
        node = head;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) {
            node->val = v[i];
            node = node->next;
        }
        return head;
    }
};