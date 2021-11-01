#include<iostream>
#include<vector>

using namespace std;

//Q: how many ways can we place n nights in a nXn chess board
// search in https://oeis.org/ for answers: search for 1, 6, 36, 412.. (https://oeis.org/A201540)


//check only in the upper side of the position (x, y)
bool isAttacked(vector<vector<int> > &board, int x, int y) {
    if (x-1 >=0 && y-2>=0) {
        if (board[x-1][y-2] == 1) {
            return true;
        }
    }
    if (x-2 >=0 && y-1>=0) {
        if (board[x-2][y-1] == 1) {
            return true;
        }
    }
    if (x-2 >=0 && y+1<=board.size()-1) {
        if (board[x-2][y+1] == 1) {
            return true;
        }
    }
    if (x-1 >=0 && y+2<=board.size()-1) {
        if (board[x-1][y+2] == 1) {
            return true;
        }
    }
    return false;

}


//gives us the number of ways k knights can be placed in board starting from x,y to last position of the board
int getNumberOfStables(vector<vector<int> > &board, int x, int y, int k) {
    if (k==0) {
        return 1;
    }
    int numberOfStables = 0;
    for (int i = x; i < board.size(); i++) {
        for (int j = (i == x? y : 0); j < board.size(); j++) {
            if (!isAttacked(board, i, j)) {                                      //prune
                board[i][j] = 1;                                                 // for checking safety in child tree of recusrion
                if(j==board.size()-1) {
                    numberOfStables+= getNumberOfStables(board, i+1, 0, k-1);
                } else {
                    numberOfStables+= getNumberOfStables(board, i, j+1, k-1);
                }
                board[i][j] = 0;                                                 //recovery
            }
        }
    }
    return numberOfStables;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > board = vector<vector<int> >(n, vector<int>(n, 0));
    int ans;
    cout<<getNumberOfStables(board, 0, 0, n);
}