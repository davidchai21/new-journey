class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (string word: words) {
            string t = "";
            for (char a:word) {
                t += m[a-'a'];
            }
            s.insert(t);
        }
        return s.size();
    }
private:
    vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};