//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int freedRoom = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(freedRoom);
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                busyRooms.push({end, room});
                count[room]++;
            } else {
                auto top = busyRooms.top(); busyRooms.pop();
                long long availTime = top.first;
                int room = top.second;

                long long duration = end - start;
                busyRooms.push({availTime + duration, room});
                count[room]++;
            }
        }

        int maxCount = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};



//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends