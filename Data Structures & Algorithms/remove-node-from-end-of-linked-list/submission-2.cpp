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
        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            len++;
        }
        cur = head;
        for (int i = 0; i < len - n - 1; i++) {
            cur = cur->next;
        }
        if (cur == head && n == len) {
            head = cur->next;
            delete(cur);
        }
        else {
            ListNode* temp = cur->next;
            if (cur->next->next != nullptr) {
                cur->next = cur->next->next;
            }
            else {
                cur->next = nullptr;
            }
            delete(temp);
        }
        return head;
    }
};
