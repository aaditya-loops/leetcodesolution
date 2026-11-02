class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int no_of1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(pair(i, j));
                }
                if (grid[i][j] == 1) {
                    no_of1++;
                }
            }
        }
        if (no_of1 == 0) {
            return 0;
        }
        int ans = 0;
        while (!q.empty()) {
            int x = q.size();
            ans++;
            for (int i = 0; i < x; i++) {
                int a = q.front().first, b = q.front().second;
                q.pop();

                if (a > 0) {
                    if (grid[a - 1][b] == 1) {
                        grid[a - 1][b] = 2;
                        no_of1--;
                        q.push(pair(a - 1, b));
                    }
                }
                if (b < m - 1) {
                    if (grid[a][b + 1] == 1) {
                        grid[a][b + 1] = 2;
                        no_of1--;
                        
                        q.push(pair(a, b + 1));
                    }
                }
                if (a < n - 1) {
                    if (grid[a + 1][b] == 1) {
                        grid[a + 1][b] = 2;
                        no_of1--;
                        q.push(pair(a + 1, b));
                    }
                }
                if (b > 0) {
                    if (grid[a][b - 1] == 1) {
                        grid[a][b - 1] = 2;
                        no_of1--;
                        q.push(pair(a, b - 1));
                    }
                }
            }
        }
        ans--;
        if (no_of1 > 0) {
            return -1;
        } else {
            return ans;
        }
        return -1;
    }
};