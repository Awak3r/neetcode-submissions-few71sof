/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* cur_old = head;
        Node* tmp = nullptr;
        Node* head_new;
        unordered_map<Node*, int> mp;
        int size = 1;
        while(cur_old){
            Node* cur_new = new Node(cur_old->val);
            mp[cur_old] = size;
            cout<<size;
            if (tmp){
                tmp->next = cur_new;
            } else{
                head_new = cur_new;
            }
            tmp = cur_new;
            cur_old = cur_old->next;
            size++;
        }
        cur_old = head;
        Node* cur_new = head_new;
        while(cur_old){
            Node* rand = cur_old->random;
            if (!rand) {
                cur_new = cur_new->next;
                cur_old = cur_old->next;
                continue;
                }
            int n = mp[rand];
            int len = 1;
            tmp = head_new;
            while(len != n){
                tmp = tmp->next;
                len++;
            }
            cur_new->random = tmp;
            cur_new = cur_new->next;
            cur_old = cur_old->next;
        }

    return head_new;
    }
};
