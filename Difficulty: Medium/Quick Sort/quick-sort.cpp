//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
public:
    // Partition function using Lomuto's partitioning scheme
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choosing the last element as pivot
        int i = low - 1; // Pointer for the smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) { // If current element is smaller than or equal to pivot
                i++;
                swap(arr[i], arr[j]); // Swap elements to place smaller elements before pivot
            }
        }
        swap(arr[i + 1], arr[high]); // Move pivot to its correct position
        return i + 1; // Return pivot index
    }

    // QuickSort function using recursion
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high); // Get partition index
            quickSort(arr, low, pi - 1); // Sort left part
            quickSort(arr, pi + 1, high); // Sort right part
        }
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends