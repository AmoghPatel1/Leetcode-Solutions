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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size() == 0) return NULL;
        vector<int> v;
        for(int i=0;i<lists.size();i++) {
            while(lists[i]) {
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) {
            cout << v[i] << " ";
        }
        
        if(v.size() == 0) return NULL;
        
        ListNode *head = new ListNode(v[0]);
        ListNode *cur = head;
        
        for(int i=1;i<v.size();i++) {
            ListNode* node = new ListNode(v[i]);
            cur->next = node;
            cur = cur->next;
        }
        return head;
    }
};