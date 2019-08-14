class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if (n==0) return 0;
        vector<int> start(n);
        vector<int> end(n);
        for (int i=0;i<n;i++) {
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int index = 0;
        int available=0;
        int room = 0;
        for (int i=0;i<n;i++) {
            while (end[index]<=start[i]) {
                index++;
                available++;
            }
            available?available--:room++;
        }
        return room;
    }
};