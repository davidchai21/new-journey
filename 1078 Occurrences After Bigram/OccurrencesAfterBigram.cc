class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        istringstream iss(text);
        string one = "";
        string two = "";
        string word = "";
        while (iss>>word) {
            if (one == first && second == two) res.push_back(word);
            one = two;
            two = word;
        }
        return res;
    }
};