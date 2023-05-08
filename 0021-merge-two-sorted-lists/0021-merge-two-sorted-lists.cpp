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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* start = ans;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                ListNode* node = new ListNode(list1->val);
                start->next = node;
                list1 = list1->next;
            } else {
                ListNode* node = new ListNode(list2->val);
                start->next = node;
                list2 = list2->next;
            }
            start = start->next;
        }
        while(list1) {
            ListNode* node = new ListNode(list1->val);
            start->next = node;
            start = start->next;
            list1 = list1->next;
        }
        while(list2) {
            ListNode* node = new ListNode(list2->val);
            start->next = node;
            start = start->next;
            list2 = list2->next;
        }
        
        return ans = ans->next;
    }
};