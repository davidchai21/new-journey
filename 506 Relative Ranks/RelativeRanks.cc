class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        vector<pair<int,int> > record(nums.size());
        for (int i=0;i<nums.size();i++) {
            record[i]=make_pair(i,nums[i]);
        }
        sort(record.begin(), record.end(), [](pair<int,int> a, pair<int,int> b){return a.second>b.second;});
        res[record[0].first]="Gold Medal";
        if (nums.size()>1) res[record[1].first]="Silver Medal";
        if (nums.size()>2) res[record[2].first]="Bronze Medal";
        for (int i=3;i<nums.size();i++) {
            res[record[i].first] = to_string(i+1);
        }
        return res;
    }
};