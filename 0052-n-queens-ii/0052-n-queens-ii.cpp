class Solution {
public:
      void solveNQueens(vector<int>& queens, int row, int n, int& count) {  
        if (row == n) {  
            count++;  
            return;  
        }  
        
        for (int col = 0; col < n; col++) {  
            queens[row] = col;  
            if (isValid(queens, row)) {  
                solveNQueens(queens, row + 1, n, count);  
            }  
        }  
    }  
       bool isValid(vector<int>& queens, int row) {  
        for (int i = 0; i < row; i++) {  
            if (queens[i] == queens[row] || abs(queens[i] - queens[row]) == row - i) {  
                return false;  
            }  
        }  
        return true;  
    }  
    int totalNQueens(int n) {
        int count = 0;  
        vector<int> queens(n);  
        solveNQueens(queens, 0, n, count);  
        return count;  
    }
};