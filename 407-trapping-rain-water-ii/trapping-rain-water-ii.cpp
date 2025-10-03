class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // min-heap: {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // push all boundary cells into heap
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        // process from lowest boundary
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                // trap water if current boundary is higher
                water += max(0, h - heightMap[nx][ny]);
                // push the updated height
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }

        return water;
    }
};
