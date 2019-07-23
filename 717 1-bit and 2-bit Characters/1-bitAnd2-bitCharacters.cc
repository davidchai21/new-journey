class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() ==1 || bits[bits.size()-2]==0) return true;
        return helper(bits, bits.size()-2);
    }
    
    bool helper(vector<int>& bits, int index) {
        if (index < 0) return true;
        if (index == 0) return bits[0]==0;
        if (bits[index]==0) return helper(bits,index-1) || bits[index-1]==1 && helper(bits,index-2);
        else if (bits[index]==1) {
            if (bits[index-1]==1) return helper(bits,index-2);
        }
        return false;
    }
};