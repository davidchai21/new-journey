class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left<right) {
            if (s[left]==s[right]) {
                left++;
                right--;
            } else return helper(s, left+1, right) || helper(s, left, right-1);
        }
        return true;
    }
    
    bool helper(string s, int i, int j) {
        while (i<j) {
            if (s[i++]!=s[j--]) return false;
        }
        return true;
    }
};