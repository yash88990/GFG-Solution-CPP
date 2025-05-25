class Solution {
  public:
    int requiredStations(const vector<int>& stations, double dist) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            count += int(gap / dist);
        }
        return count;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0;
        double high = stations[n - 1] - stations[0];
        double eps = 1e-6;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            int needed = requiredStations(stations, mid);
            if (needed > k)
                low = mid;
            else
                high = mid;
        }

        return round(high * 100) / 100.0;  // Round to 2 decimal places
    }
};
