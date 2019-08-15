class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        m.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val)!=m.end()) return false;
        record.push_back(val);
        m[val]=record.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val)==m.end()) return false;
        int last = record.back();
        m[last]=m[val];
        record[m[val]]=last;
        m.erase(val);
        record.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return record[rand()%record.size()];
    }
private:
    unordered_map<int,int> m;
    vector<int> record;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */