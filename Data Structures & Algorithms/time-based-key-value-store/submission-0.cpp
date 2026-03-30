class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> res;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        res[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if (res.find(key) == res.end()) {
            return "";
        }
        int seen=0;
        for(const auto& [time, _] : res[key]) {
            if(time <= timestamp) {
                seen = max(seen, time);
            }
        }
        return seen==0 ? "" : res[key][seen].back();
    }
};
