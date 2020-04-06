#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

// accept
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mp;
    unordered_map<string, unordered_map<string, vector<int>>> dist;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        dist[mp[id].first][stationName].push_back(t - mp[id].second);
    }

    double getAverageTime(string startStation, string endStation) {
        double sum = 0.0;
        for(auto& e  : dist[startStation][endStation]) {
            sum += e;
        }
        // cout << "start: " << startStation << " end: " << endStation << " avg: " << sum / dist[startStation][endStation].size() << endl;
        return sum / dist[startStation][endStation].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, char *argv[])
{
    UndergroundSystem undergroundSystem;

    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    undergroundSystem.getAverageTime("Paradise", "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
    undergroundSystem.checkOut(10, "Waterloo", 38);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0


    return 0;
}
