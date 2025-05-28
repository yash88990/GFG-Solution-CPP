class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        // Map to store column pairs seen in previous rows
        unordered_map<int, unordered_set<int>> colpairs;
        
        for (int i = 0; i < r; i++) {
            // For each row, find all pairs of columns (j, k) where mat[i][j] and mat[i][k] == 1
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    for (int k = j + 1; k < c; k++) {
                        if (mat[i][k] == 1) {
                            // If this column pair (j, k) has been seen before in a previous row,
                            // that means a rectangle is formed
                            if (colpairs[j].count(k)) {
                                return true;
                            }
                            // Otherwise, store this pair for future comparison
                            colpairs[j].insert(k);
                        }
                    }
                }
            }
        }
        
        // No rectangle found
        return false;
    }
};
