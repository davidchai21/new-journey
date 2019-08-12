class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int index = 0;
        int res = 0;
        while (index<flowerbed.size() && flowerbed[index]==0) index++;
        if (index == flowerbed.size()) return (index+1)/2>=n;
        res+=index/2;
        while (index<flowerbed.size()) {
            int j=index+1;
            while (j<flowerbed.size() && flowerbed[j]==0) j++;
            if (j==flowerbed.size()) res+=(j-index-1)/2;
            else res+=max((j-index-2)/2, 0);
            index = j;
        }
        cout<<res<<endl;
        return res>=n;
    }
};