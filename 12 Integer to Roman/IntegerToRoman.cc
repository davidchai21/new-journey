class Solution {
public:
    string intToRoman(int num) {
        return thousandth[num/1000] + hundredth[(num%1000)/100] + tenth[(num%100)/10] + unit[num%10];
    }
private:
    vector<string> unit{"","I","II","III","IV","V","VI","VII","VIII","IX"};
    vector<string> tenth{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> hundredth{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> thousandth{"","M","MM","MMM"};
};