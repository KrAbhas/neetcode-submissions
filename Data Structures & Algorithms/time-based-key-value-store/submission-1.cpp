class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> um;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (um.find(key) == um.end() || um[key][0].first > timestamp) return "";
        vector<pair<int, string>>& opts = um[key];
        int l = 0, r = opts.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (opts[mid].first <= timestamp)
                l = mid;
            else r = mid;
        }
        return opts[l].second;
    }
};
