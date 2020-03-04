#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>

using namespace std;

// 4ms, 100.00%
// 8.8MB, 100.00%
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {

        vector<int> v1 = parse(date1);
        vector<int> v2 = parse(date2);

        if(v2[0] >= v1[0] || v2[1] >= v1[1] || v2[2] >= v1[2]) {
            v1 = parse(date2);
            v2 = parse(date1);
        }

        time_t days = abs(getTime(v1) - getTime(v2)) / 24 / 3600;
        return days >= 0 ? days : -1 * days;
    }

    time_t getTime(vector<int>& t) {
        tm info;
        info.tm_year = t[0] - 1900;
        info.tm_mon = t[1] - 1;
        info.tm_mday = t[2];
        info.tm_hour = info.tm_min = info.tm_sec = 0;
        return mktime(&info);
    }

    // bool isLeapYear(int y) {
    //     return (y % 4 == 0) && ((y % 100 != 0) || y % 400 == 0);
    // }

    vector<int> parse(string date) {
        if(date.length() == 0) return vector<int>();
        vector<int> res;
        char* token;
        const char* delim = "-";


        char ori[date.length() + 1];
        strcpy(ori, date.c_str());
        token = strtok(ori, delim);
        while(token){
            res.push_back(atoi(token));
            token = strtok(nullptr, "-");
        }
        return res;
    }

};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.daysBetweenDates("2074-09-12", "1983-01-08") << endl;
    return 0;
}
