//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Boundary check and base case
        if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != oldColor)
            return;

        // Fill current pixel
        image[x][y] = newColor;

        // Move in 4 directions
        dfs(image, x + 1, y, oldColor, newColor); // down
        dfs(image, x - 1, y, oldColor, newColor); // up
        dfs(image, x, y + 1, oldColor, newColor); // right
        dfs(image, x, y - 1, oldColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image; // no change needed

        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends