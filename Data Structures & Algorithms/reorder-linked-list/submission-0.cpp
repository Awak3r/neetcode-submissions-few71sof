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
    ListNode* find_1_do_end(ListNode* hh){
        ListNode* cur = hh;
        while(cur->next && cur->next->next){
            cur= cur->next;
        }
        return cur;
    }
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        while (cur){
            ListNode* tmp = find_1_do_end(cur);
            if (tmp == cur) break;
            ListNode* nxt = cur->next;
            cur->next = tmp->next;
            cur->next->next = nxt;
            tmp->next = nullptr;
            cur = nxt;
        }
    }
};
