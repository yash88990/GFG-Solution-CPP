// User function template in C++

class Solution {
  public:
  
int findUnion(vector<int>& a, vector<int>& b) {
    vector<int> unionVec;

    // Step 1: Add all elements from both arrays
    for (int i = 0; i < a.size(); i++) {
        unionVec.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        unionVec.push_back(b[i]);
    }

    // Step 2: Sort the vector
    sort(unionVec.begin(), unionVec.end());

    // Step 3: Remove duplicates manually
    vector<int> uniqueVec;
    uniqueVec.push_back(unionVec[0]);
    for (int i = 1; i < unionVec.size(); i++) {
        if (unionVec[i] != unionVec[i - 1]) {
            uniqueVec.push_back(unionVec[i]);
        }
    }

    // Step 4: Return the size of unique vector (number of elements in union)
    return uniqueVec.size();
}

};