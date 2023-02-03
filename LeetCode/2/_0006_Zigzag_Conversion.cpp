class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res="";
        int n = s.size();
        int col = ceil(n / (2 * numRows - 2.0)) * (numRows - 1) ;
        vector<vector<char>> mat(numRows, vector<char>(col, ' '));
        int currRow = 0, currCol = 0;
        int idx = 0;
        while (idx < n) {
            while (currRow < numRows && idx < n) {
                mat[currRow][currCol] = s[idx];
                currRow++;
                idx++;
            }
            currRow -= 2;
            currCol++;
            while (currRow > 0 && currCol < col && idx < n) {
                mat[currRow][currCol] = s[idx];
                currRow--;
                currCol++;
                idx++;
            }
        }
      
        for (auto& row: mat) {
            for (auto& c: row) {
                if (c != ' ')res += c;
            }
        }
        return res;
    }
};