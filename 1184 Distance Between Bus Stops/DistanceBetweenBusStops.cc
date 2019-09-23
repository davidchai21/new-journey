class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start == destination) return 0;
        int n=distance.size();
        int forward = 0;
        int backward = 0;
        for (int i=start;i!=destination;i=(i+1)%n) {
            forward += distance[i];
        }
        for (int i=start;i!=destination;i=(i+n-1)%n) {
            backward += distance[(i+n-1)%n];
        }
        return min(forward, backward);
    }
};