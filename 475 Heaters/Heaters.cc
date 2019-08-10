class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty() || heaters.empty()) return 0;
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i=0;i<houses.size();i++) {
            int left = 0;
            int right = heaters.size()-1;
            while (left+1<right) {
                int mid = left + (right-left)/2;
                if (heaters[mid]==houses[i]) {
                    left = right = mid;
                } else if (heaters[mid]>houses[i]) right = mid;
                else left = mid;
            }
            res = max(res, min(abs(heaters[left]-houses[i]), abs(heaters[right]-houses[i])));
        }
        return res;
    }
};