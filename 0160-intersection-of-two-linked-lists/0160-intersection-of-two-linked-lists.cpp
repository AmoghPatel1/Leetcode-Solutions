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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* node = headA;
        while(node) {
            len1 += 1;
            node = node->next;
        }
        node = headB;
        while(node) {
            len2 += 1;
            node = node->next;
        }
        ListNode* node2;
        if(len1 < len2) {
            node = headB;
            while(len2 != len1) {
                node = node->next;
                len2 -= 1;
            }
            node2 = headA;
            while(node != node2) {
                node = node->next;
                node2 = node2->next;
            }
        } else {
            node = headA;
            while(len1 != len2) {
                node = node->next;
                len1 -= 1;
            }
            node2 = headB;
            while(node != node2) {
                node = node->next;
                node2 = node2->next;
            }
        }
        return node;
    }
};