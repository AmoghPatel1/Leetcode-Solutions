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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        vector<int> v;
        while(head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        ListNode* front = new ListNode(v[n-1]);
        ListNode* ans = front;
        for(int i=n-2;i>=0;i--) {
            ListNode* node = new ListNode(v[i]);
            front->next = node;
            front = front->next;
        }
        return ans;
    }
};