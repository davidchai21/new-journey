class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        if (list1.empty() || list2.empty()) return res;
        unordered_map<string,int> m;
        for (int i=0;i<list1.size();i++) {
            m[list1[i]] = i;
        }
        int sum = INT_MAX;
        for (int i=0;i<list2.size();i++) {
            if (m.find(list2[i])!=m.end()) {
                if (i+m[list2[i]]<sum) {
                    sum = i+m[list2[i]];
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (i+m[list2[i]] == sum) res.push_back(list2[i]);
            }
        }
        return res;
    }
};