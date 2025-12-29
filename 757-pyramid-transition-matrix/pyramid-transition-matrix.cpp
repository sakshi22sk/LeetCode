class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> memo;

    bool dfs(string bottom) {
        // If pyramid height becomes 1 → success
        if (bottom.size() == 1) return true;

        // Memoization check
        if (memo.count(bottom)) return false;

        vector<string> nextRows;
        buildNext(bottom, 0, "", nextRows);

        for (string &row : nextRows) {
            if (dfs(row)) return true;
        }

        memo.insert(bottom);
        return false;
    }

    void buildNext(string &bottom, int idx, string curr, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            buildNext(bottom, idx + 1, curr + ch, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
