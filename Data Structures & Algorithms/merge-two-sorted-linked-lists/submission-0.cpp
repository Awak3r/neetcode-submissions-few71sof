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
    ListNode* mergeTwoLists(ListNode* cur1, ListNode* cur2) {
        ListNode hui;
        ListNode* res = &hui;
        while(cur1 != nullptr && cur2 != nullptr){
            if (cur1->val < cur2->val){
                res->next = cur1;
                res = res->next;
                cur1= cur1->next;
            } else {
                res->next = cur2;
                res = res->next;
                cur2= cur2->next;
            }
        }
        if (cur1 != nullptr){
            res->next = cur1;
        } else if (cur2 != nullptr) {
            res->next = cur2;
        }
        return hui.next;
    }
};
