class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i=0;i<=num;i++) {
            vector<int> hour, minute;
            helper(hour, 12, i, 0, 2);
            helper(minute, 60, num-i, 0, 0);
            for (int i:hour) cout<<i<<" ";
            cout<<endl;
            //for (int i:minute) cout<<i<<" ";
            for (int h:hour) {
                for (int m:minute) {
                    res.push_back(timeToString(h,m));
                }
            }
        }
        return res;
    }
    
    void helper(vector<int>& time, int threshold, int remain, int sum, int index) {
        if (remain == 0 && sum<threshold) {
            time.push_back(sum);
            return;
        }
        for (int i=index;i<6;i++) {
            helper(time, threshold, remain-1, sum+table[i], i+1);
        }
    }
    
    string timeToString(int hour, int minute) {
        return to_string(hour)+":"+(minute<10?"0":"")+to_string(minute);
    }
private:
    vector<int> table = {32, 16, 8, 4, 2, 1};
};