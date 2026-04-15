struct ListNode{
    int value;
    int key;
    ListNode* next;
    ListNode* prev;
    ListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _head = nullptr;
        _tail = nullptr;
    }
    
    int get(int key) {
        if (_mp.find(key) == _mp.end()){
            return -1;
        }
        int res = _mp[key]->value;
        del(_mp[key]);
        push_back(key, res);
        _mp[key] = _tail;
        return res;
    }
    
    void put(int key, int value) {
        if (_mp.find(key) == _mp.end()){
            if (_size == _capacity){
                int old_key = _head->key;
                pop_front();
                _mp.erase(old_key);
            }
            push_back(key, value);
            _mp[key] = _tail;
        } else {
            del(_mp[key]);
            push_back(key, value);
            _mp[key] = _tail;
        }
    }
    void push_back(int key, int value){
        ListNode* cur = new ListNode(key, value);
        if (!_head){
            _head = cur;
            _tail = cur;
        } else {
            _tail->next = cur;
            cur->prev = _tail;
            _tail = cur;
        }
        _size++;
    }
    void pop_front() {
        if (_head == nullptr) {
            return;
        }
        ListNode* tmp = _head;
        if (_head == _tail) {
            _head = nullptr;
            _tail = nullptr;
        } else {
            _head = _head->next;
            _head->prev = nullptr;
        }
        delete tmp;
        _size--;
    }
    void pop_back() {
        if (_tail == nullptr){
            return;
        }
        ListNode* tmp = _tail;
        if (_head == _tail){
            _head = nullptr;
            _tail = nullptr;
        } else {
            _tail = _tail->prev;
            _tail->next = nullptr;
        }
        delete tmp;
        _size--;

    }
    void del(ListNode* node){
        if (node == _head){
            pop_front();
        } else if (node == _tail){
            pop_back();
        } else {
            ListNode* tmp = node;
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete(node);
            _size--;
        }
    }
private:
    ListNode* _head;
    ListNode* _tail;
    unordered_map<int, ListNode*> _mp;
    int _capacity;
    int _size = 0;
};
