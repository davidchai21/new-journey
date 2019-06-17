class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<string> digits;
        for (string log: logs) {
            size_t pos = log.find(' ')+1;
            if (isdigit(log[pos])) digits.push_back(log);
            else res.push_back(log);
        }
        sort(res.begin(), res.end(), [](string a, string b){
            size_t pos1 = a.find(' ')+1;
            size_t pos2 = b.find(' ')+1;
            return a.substr(pos1)<b.substr(pos2) || a.substr(pos1)==b.substr(pos2) && a<b;
        });
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};