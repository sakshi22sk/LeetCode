class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        
        // Priority order for business lines
        unordered_map<string, int> order {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<pair<string, string>> valid; // (businessLine, code)
        
        for (int i = 0; i < n; ++i) {
            if (!isActive[i]) continue;          // must be active
            if (!isValidCode(code[i])) continue; // must be non-empty & valid characters
            if (!order.count(businessLine[i])) continue; // must be one of four categories

            valid.emplace_back(businessLine[i], code[i]);
        }
        
        // Sort by businessLine priority and then code lexicographically
        sort(valid.begin(), valid.end(), [&](auto &a, auto &b) {
            if (order[a.first] != order[b.first]) 
                return order[a.first] < order[b.first];
            return a.second < b.second;
        });
        
        // Extract only the coupon codes
        vector<string> result;
        result.reserve(valid.size());
        for (auto &p : valid) {
            result.push_back(p.second);
        }
        return result;
    }

private:
    bool isValidCode(const string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false; // alphanumeric or underscore
        }
        return true;
    }
};
