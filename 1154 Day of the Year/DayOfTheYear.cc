class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+date[3]-'0';
        int month = (date[5]-'0')*10+date[6]-'0';
        int day = (date[8]-'0')*10+date[9]-'0';
        for (int i=0;i<month-1;i++) day+=record[i];
        if (year==2000 || year%100 && year%4==0) {
            if (month>2) day++;
        }
        return day;
    }
private:
    vector<int> record = {31,28,31,30,31,30,31,31,30,31,30,31};
};