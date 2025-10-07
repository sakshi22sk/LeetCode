class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);       // default 1 for dry days
        unordered_map<int, int> full; // lake -> last filled day
        set<int> dryDays;             // available dry days (indices)
        
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            
            if (lake > 0) {
                ans[i] = -1;  // raining day
                
                // If this lake is already full, find dry day after last rain
                if (full.count(lake)) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) return {}; // no available dry day
                    ans[*it] = lake;   // dry this lake on that dry day
                    dryDays.erase(it);
                }
                full[lake] = i;  // update last rain day
            } 
            else {
                dryDays.insert(i); // add this dry day for future use
            }
        }
        return ans;
    }
};
