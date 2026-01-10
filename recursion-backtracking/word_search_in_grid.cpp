#include <bits/stdc++.h>
using namespace std;

// Easy-Med
// https://leetcode.com/problems/word-search/
// Good Backtracking practice.

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (check(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word, int checkChar) {
        if (board[i][j] != word[checkChar]) {
            return false;
        }
        if (checkChar == word.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        // UP
        if (i > 0 && !visited[i - 1][j]) {
            if (check(board, visited, i - 1, j, word, checkChar + 1)) {
                return true;
            }
        }
        // DOWN
        if (i < board.size() - 1 && !visited[i + 1][j]) {
            if (check(board, visited, i + 1, j, word, checkChar + 1)) {
                return true;
            }
        }
        // LEFT
        if (j > 0 && !visited[i][j - 1]) {
            if (check(board, visited, i, j - 1, word, checkChar + 1)) {
                return true;
            }
        }
        // RIGHT
        if (j < board[0].size() - 1 && !visited[i][j + 1]) {
            if (check(board, visited, i, j + 1, word, checkChar + 1)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};