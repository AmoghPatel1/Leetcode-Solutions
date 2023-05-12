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
    ListNode* removeNthFromEnd(ListNode* head, int n) {       
        vector<int> v;
        ListNode* node = head;
        while(node) {
            v.push_back(node->val);
            node = node->next;
        }
        if(v.size() == 1 && n==1) return nullptr;
        int index = v.size()-n;
        if(index == 0) return head->next;
        node = head;
        while(index-1) {
            node = node->next;
            index-=1;
        }
        node->next = node->next->next;
        return head;
    }
};