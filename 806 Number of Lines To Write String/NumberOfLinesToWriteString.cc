class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int length = 0;
        const int limit = 100;
        int lines = 1;
        for (char c:S) {
            if (length+widths[c-'a']<=limit) length += widths[c-'a'];
            else {
                lines++;
                length = widths[c-'a'];
            }
        }
        return {lines, length};
    }
};