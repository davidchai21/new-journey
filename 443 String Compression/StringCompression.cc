class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int start = 0;
        for (int i=1;i<chars.size();i++) {
            if (chars[i]==chars[start]) count++;
            else {
                if (count>2) {
                    i = modifyVec(chars, start, count);
                    start = i;
                } else {
                    if (count == 2) chars[start+1]='2'; 
                    start = i;
                }
                count = 1;
            }
        }
        if (count>2) modifyVec(chars, start, count);
        else if (count==2) chars.back() = '2';
        return chars.size();
    }
    
    int modifyVec(vector<char>& chars, int start, int count) {
        int numBit = countBit(count);
        int n = count-numBit-1;
        for (int i=start+numBit;i>start;i--) {
            chars[i]=(count%10)+'0';
            count/=10;
        }
        int rem = start+numBit+1;
        while (n--) chars.erase(chars.begin()+rem);
        return start+numBit+1;
    }
    
    int countBit(int n) {
        int res = 0;
        while (n) {
            res++;
            n/=10;
        } 
        return res;
    }
};