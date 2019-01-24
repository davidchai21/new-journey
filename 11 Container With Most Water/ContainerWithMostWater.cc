class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = (right - left)*min(height[left], height[right]);
        while (left<right) {
            if (height[left]<height[right]) {
                int i = left + 1;
                while (i<right && height[i]<=height[left]) i++;
                if (i == right) break;
                res = max(res, (right - i)*min(height[i], height[right]));
                left = i;
            } else {
                int j = right -1;
                while (j>left && height[j]<=height[right]) j--;
                if (j==left) break;
                res = max(res, (j-left)*min(height[j], height[left]));
                right = j;
            }
        }
        return res;
    }
};