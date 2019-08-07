class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i=1;i<nums.size();i++) {
            nums[i]+=nums[i-1];
        }
        num = nums;
    }
    
    int sumRange(int i, int j) {
        return i==0?num[j]:num[j]-num[i-1];
    }
private:
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */