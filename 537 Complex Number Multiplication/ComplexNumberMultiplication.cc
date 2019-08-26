class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int,int> x=getPart(a);
        pair<int,int> y=getPart(b);
        return to_string(x.first*y.first-x.second*y.second)+"+"+to_string(x.first*y.second+x.second*y.first)+"i";
    }
    
    pair<int,int> getPart(string a) {
        int plusSign = 0;
        int index = 0;
        int real=0;
        int unreal = 0;
        while (a[index]!='+') {
            if (isdigit(a[index])) real=real*10+a[index]-'0';
            index++;
        }
        plusSign = index++;
        while (index<a.size()) {
            if (isdigit(a[index])) unreal=unreal*10+a[index]-'0';
            index++;
        }
        if (a[0]=='-') real=-real;
        if (a[plusSign+1]=='-') unreal=-unreal;
        return make_pair(real, unreal);
    }
};