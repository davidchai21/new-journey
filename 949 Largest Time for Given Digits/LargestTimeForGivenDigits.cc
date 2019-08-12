class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res = "";
        int second = -1;
        string hour, minute;
        for (int i=0;i<3;i++) {
            for (int j=i+1;j<4;j++) {
                helper(A, i, j, hour, minute, second);
            }
        }
        return second == -1?"":hour+":"+minute;
    }
    
    void helper(vector<int>& A, int i, int j, string& finalHour, string& finalMinute, int& second) {
        vector<int> hour, minute;
        if (A[i]*10+A[j]<24) hour.push_back(A[i]*10+A[j]);
        if (A[j]*10+A[i]<24) hour.push_back(A[j]*10+A[i]);
        int m = -1;
        int n = -1;
        for (int k=0;k<4;k++) {
            if (i==k || j==k) continue;
            if (m==-1) m=k;
            else n=k;
        }
        if (A[m]*10+A[n]<60) minute.push_back(A[m]*10+A[n]);
        if (A[n]*10+A[m]<60) minute.push_back(A[n]*10+A[m]);
        if (hour.empty() || minute.empty()) return;
        int maxHour = max(hour[0], hour.back());
        int maxMin = max(minute[0], minute.back());
        int sum = 60*maxHour+maxMin;
        if (sum>second) {
            second = sum;
            finalHour = (maxHour<10?"0":"")+to_string(maxHour);
            finalMinute = (maxMin<10?"0":"")+to_string(maxMin);
        }
    }
};