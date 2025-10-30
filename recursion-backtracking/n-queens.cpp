#include<iostream>
#include<vector>

using namespace std;

// Good . Medium. (But Hard tag in LC) https://leetcode.com/problems/n-queens/

bool isAttackedFromAbove(vector<vector<int> > &board, int x, int y) {
    if (x==0) {
        return false;
    }
    int leftdiagonal = y-1, rightdiagonal = y+1;
    for(int i = x-1; i>=0; i--) {//check the ith row above i goes from x-1 to 0
        if (board[i][y] == 1) {
            return true;
        }
        if (leftdiagonal >=0) {
            if (board[i][leftdiagonal] == 1) {
                return true;
            }
        }
        if (rightdiagonal <= board.size() -1) {
            if (board[i][rightdiagonal] == 1) {
                return true;
            }
        }
        leftdiagonal--;
        rightdiagonal++;
    }
    return false;
}

//part of backtracking : prune and recover the original
int getNumberOfStables(vector<vector<int> > &board, int currentRow) {

    int possibleStables = 0;
    for(int j = 0; j< board.size(); j++) {
        if(!isAttackedFromAbove(board, currentRow, j)) {           // prune
            if (currentRow == board.size()-1) {
                possibleStables++;
            } else {
                board[currentRow][j] = 1;                           //for child tree
                possibleStables+=getNumberOfStables(board, currentRow+1);
                board[currentRow][j] = 0;                           //recover the original
            }
        }
    }
    return possibleStables;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > board = vector<vector<int> >(n, vector<int>(n, 0));
    cout<<getNumberOfStables(board, 0);
}


// Solve For the LC 
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        string s;
        for (int i = 0; i < n; i++)
        {
            s += '.';
        }

        vector<string> startConfig(n, s);
        vector<vector<string>> ans;

        getNQueens(startConfig, n, 0, ans);

        return ans;
    }

    void getNQueens(vector<string> &cur, int n, int curRow, vector<vector<string>> &ans)
    {
        if (curRow >= n)
        {
            ans.push_back(cur);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (!isAttacked(cur, n, curRow, j))
            {
                cur[curRow][j] = 'Q';
                getNQueens(cur, n, curRow + 1, ans);
                cur[curRow][j] = '.';
            }
        }
    }

    bool isAttacked(vector<string> &cur, int n, int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            if (cur[i][y] == 'Q')
            {
                return true;
            }
        }
        int i = x - 1, left_diagonal_col = y - 1, right_diagonal_col = y + 1;
        while (i >= 0)
        {
            if (left_diagonal_col >= 0 && cur[i][left_diagonal_col] == 'Q')
            {
                return true;
            }
            if (right_diagonal_col < n && cur[i][right_diagonal_col] == 'Q')
            {
                return true;
            }
            i--;
            left_diagonal_col--;
            right_diagonal_col++;
        }
        return false;
    }
};