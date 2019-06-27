class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        head = new Node(-1,-1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        Node* cur = head;
        while (cur->next) {
            if (cur->next->value.first == key) {
                cur->next->value.second = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new Node(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Node* cur = head->next;
        while (cur) {
            if (cur->value.first == key) return cur->value.second;
            cur = cur->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Node* cur = head;
        while (cur->next) {
            if (cur->next->value.first == key) {
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
    }
private:
    struct Node {
        pair<int, int> value;
        Node* next = NULL;
        
        Node() {}
        Node(int a, int b) {
            value = make_pair(a,b);
        }
    };
    Node* head;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


 class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        dic = vector<int>(1000001, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        dic[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return dic[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        dic[key]=-1;
    }
private:
    vector<int> dic;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */