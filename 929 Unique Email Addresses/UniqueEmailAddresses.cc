class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string email: emails) {
            int found = email.find_first_of('@');
            string localName = getLocalName(email.substr(0,found));
            s.insert(localName + email.substr(found));
        }
        return s.size();
    }
private:
    string getLocalName(string s) {
        string res = "";
        for (char a:s) {
            if (a == '+') break;
            if (a != '.') res += a;
        }
        return res;
    }
};