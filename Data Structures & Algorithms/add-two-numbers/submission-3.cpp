class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = nullptr;
        ListNode* head = nullptr;
        int perenos = 0;

        while (l1 || l2 || perenos) {
            int n1 = 0, n2 = 0;

            if (l1) {
                n1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                n2 = l2->val;
                l2 = l2->next;
            }

            int n3 = n1 + n2 + perenos;
            perenos = n3 / 10;

            ListNode* cur = new ListNode(n3 % 10);

            if (tmp) {
                tmp->next = cur;
            } else {
                head = cur;
            }

            tmp = cur;
        }

        return head;
    }
};