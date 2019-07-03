class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        head = new ListNode(0);
    }
    
    void add(int key) {
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val == key) return;
            cur = cur->next;
        }
        cur->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val == key) {
                cur->next = cur->next->next;
                return;
            }
            cur = cur->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val == key) return true;
            cur = cur->next;
        }
        return false;
    }
private:
    struct ListNode {
        int val;
        ListNode* next;
        
        ListNode() {};
        ListNode(int value): val(value) {next = NULL;};
    };
    ListNode* head;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */