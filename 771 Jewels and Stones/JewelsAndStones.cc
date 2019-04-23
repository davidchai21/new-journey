class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> letter(256, false);  
        for (char a:J) {
            letter[a] = true;
        }
        int res = 0;
        for (char a:S) {
            if (letter[a]) res++;
        }
        return res;
    }
};