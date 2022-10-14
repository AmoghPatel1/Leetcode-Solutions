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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* node = head;
        int length = 0;
        while(node != NULL) {
            length +=1;
            node=node->next;
        }
        cout << length << endl;
        int mid = length/2;
        if(length == 1) return nullptr;
        node = head;
        for(int i=0;i<mid-1;i++) {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};