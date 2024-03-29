#include<iostream>
#include<vector>

using namespace std;

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