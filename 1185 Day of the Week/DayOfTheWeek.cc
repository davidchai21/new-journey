class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int sum = 4;
        for (int i=1971;i<year;i++) {
            sum += 365;
            if (i%100==0 && i%400==0 || i%4==0 && i%100) {
                ++sum;
            }
        }
        for (int i=1;i<month;i++) {
            sum += days[i-1];
        }
        if (month>2 && (year%100==0 && year%400==0 || year%4==0 && year%100)) ++sum;
        sum += day-1;
        sum%=7;
        return weekday[sum];
    }
private:
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<string> weekday = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
};