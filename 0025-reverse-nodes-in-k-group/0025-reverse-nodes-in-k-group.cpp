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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        int len = 0;
        ListNode* root = head;
        while(root) {
            len += 1;
            root = root->next;
        }
        int i=0;
        root = head;
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        while(i<len) {
            if(i+k > len) {
                cur->next = root;
                return ans->next;
            }
            int t = k;
            while(t-- && root) {
                v.push_back(root->val);
                root = root->next;
                i+=1;
            }
            
            ListNode* now = new ListNode(v[v.size()-1]);
            ListNode* node = now;
            for(int j = v.size()-2;j>=0;j--) {
                node->next  = new ListNode(v[j]);
                node = node->next;
            }
            cur->next = now;
            cur = node;
            v.clear();
        }
        return ans->next;
    }
};