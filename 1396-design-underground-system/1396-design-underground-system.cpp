class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInM;
    unordered_map<string,pair<int,int>> path;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
           checkInM[id] = {stationName,t}; 
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInM[id];
        
        string route = checkIn.first+"_"+stationName;
        int totalTime = t-checkIn.second;
        
        path[route].first += totalTime;
        path[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;
        
        auto checkOutV = path[route];
        
        return (double)(checkOutV.first/(double)checkOutV.second);
    }
};
