class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m;
        for(int i=0;i<arr2.size();i++) m[arr2[i]]=i;
        for (int i=0;i<arr1.size();i++) {
            if (m.find(arr1[i])==m.end()) m[arr1[i]]=arr2.size()+arr1[i]+1;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b){return m[a]<m[b];});
        return arr1;
    }
};