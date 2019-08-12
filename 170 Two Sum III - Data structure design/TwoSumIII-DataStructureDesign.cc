class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        m.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++) {
            int diff = value-it->first;
            if (diff!=it->first && m.find(diff)!=m.end() || diff==it->first && it->second>1) return true; 
        }
        return false;
    }
private:
    unordered_map<int,int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */