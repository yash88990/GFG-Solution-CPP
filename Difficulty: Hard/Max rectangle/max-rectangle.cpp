class Solution {
public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: Build height vector (histogram)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            // Step 2: For each column, expand to left & right without stack
            for (int j = 0; j < m; j++) {
                if (height[j] == 0) continue;

                int left = j, right = j;

                // Move left while heights are >= height[j]
                while (left > 0 && height[left - 1] >= height[j])
                    left--;

                // Move right while heights are >= height[j]
                while (right < m - 1 && height[right + 1] >= height[j])
                    right++;

                int width = right - left + 1;
                int area = width * height[j];
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
