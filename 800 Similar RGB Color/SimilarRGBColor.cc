class Solution {
public:
    string similarRGB(string color) {
        char a = getClosest(color.substr(1,2));
        char b = getClosest(color.substr(3,2));
        char c = getClosest(color.substr(5,2));
        string res = "#######";
        res[1]=res[2]=a;
        res[3]=res[4]=b;
        res[5]=res[6]=c;
        return res;
    }
    
    char getClosest(string part) {
        int num = stoi(part, nullptr, 16);
        int d = num/17;
        int t;
        if (17*(d+1)<=255 && 17*(d+1)-num<num-17*d) t = d+1;
        else t = d;
        return (t>9)?(t-10+'a'):(t+'0');
    }
};