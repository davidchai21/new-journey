class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) return letters[0];
        int left = 0;
        int right = letters.size()-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (letters[mid]<=target) left = mid;
            else right = mid;
        }
        if (letters[left]>target) return letters[left];
        return letters[right];
    }
};