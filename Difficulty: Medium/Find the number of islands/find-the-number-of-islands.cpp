//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int n, m;

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;

        // 8 directions: up, down, left, right, and all diagonals
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int dir = 0; dir < 8; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                !visited[newX][newY] && grid[newX][newY] == 'L') {
                dfs(newX, newY, grid, visited);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends