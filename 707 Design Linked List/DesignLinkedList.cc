class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
        tail = head;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index>=size) return -1;
        ListNode* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* first = new ListNode(val);
        first->next = head->next;
        head->next = first;
        if (size == 0) tail = first;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* last = new ListNode(val);
        tail->next = last;
        tail = last;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index>size || index < 0) return;
        else if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode* cur = head;
        while (index--) cur = cur->next;
        ListNode* now = new ListNode(val);
        now->next = cur->next;
        cur->next = now;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index<0) return;
        ListNode* cur = head;
        int i = index;
        while (i--) cur = cur->next;
        ListNode* delete_node = cur->next;
        cur->next = delete_node->next;
        if (index == size-1) tail = cur;
        delete delete_node;
        size--;
    }
private:
    struct ListNode {
        int val;
        ListNode* next = NULL;
        ListNode(int n): val(n) {}
    };
    ListNode* head = new ListNode(0);
    ListNode* tail = head->next;
    int size=0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */