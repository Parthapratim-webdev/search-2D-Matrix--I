
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchInrow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == mat[row][mid]) {
                return true;
            } 
            else if (target > mat[row][mid]) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchInrow(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (target >= mat[midRow][0] &&
                target <= mat[midRow][n - 1]) {
                return searchInrow(mat, target, midRow);
            } 
            else if (target > mat[midRow][n - 1]) {
                startRow = midRow + 1;
            } 
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (sol.searchInrow(mat, target)) {
        cout << "Target found in the matrix." << endl;
    } 
    else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}

