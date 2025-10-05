class Solution {
public:
    int m, n;
    vector<vector<int>> pacific, atlantic, heights;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c, vector<vector<int>>& ocean) {
        ocean[r][c] = 1;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (ocean[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue; // can flow only from high to low
            dfs(nr, nc, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        m = heights.size();
        n = heights[0].size();

        pacific = vector<vector<int>>(m, vector<int>(n, 0));
        atlantic = vector<vector<int>>(m, vector<int>(n, 0));

        // Pacific (top row + left col)
        for (int i = 0; i < m; ++i) dfs(i, 0, pacific);
        for (int j = 0; j < n; ++j) dfs(0, j, pacific);

        // Atlantic (bottom row + right col)
        for (int i = 0; i < m; ++i) dfs(i, n - 1, atlantic);
        for (int j = 0; j < n; ++j) dfs(m - 1, j, atlantic);

        // Collect cells that can reach both oceans
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
