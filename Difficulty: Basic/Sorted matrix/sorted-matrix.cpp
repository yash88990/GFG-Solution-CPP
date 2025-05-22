// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> temp;

        // Step 1: Flatten the matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp.push_back(Mat[i][j]);
            }
        }

        // Step 2: Sort the array
        sort(temp.begin(), temp.end());

        // Step 3: Fill back the matrix row by row
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Mat[i][j] = temp[idx++];
            }
        }

        return Mat;
    }
};
