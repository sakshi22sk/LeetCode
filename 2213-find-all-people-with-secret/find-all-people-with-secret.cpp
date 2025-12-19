class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[y] = x;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // 0 shares secret with firstPerson at time 0
        unite(0, firstPerson);

        // sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            // process same time meetings
            while (i < meetings.size() && meetings[i][2] == time) {
                unite(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
                i++;
            }

            // reset people not connected to 0
            for (int p : people) {
                if (find(p) != find(0))
                    parent[p] = p;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                ans.push_back(i);
        }
        return ans;
    }
};
