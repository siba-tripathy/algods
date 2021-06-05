#include<iostream>
#include<vector>

using namespace std;

bool checkMoveCountValid(vector<string>& board) {
    //condition for reachability: x = o || o+1
    int x=0,o=0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (board[i][j] == 'X') {
                x++;
            } else if (board[i][j] == 'O') {
                o++;
            }
        }
    }
    if (x == o || x == o+1) {
        return true;
    }
    return false;
}

bool checkIfWon(vector<string>& board, char playerSign) {
    //check if someone won row-wise
    for (int i=0; i<3; i++) {
        if ((board[i][0] == playerSign) && (board[i][1] == playerSign) && (board[i][2] == playerSign)) {
            return true;
        }
    }

    //check if someone won column-wise
    for (int j=0; j<3; j++) {
        if ((board[0][j] == playerSign) && (board[1][j] == playerSign) && (board[2][j] == playerSign)) {
            return true;
        }
    }

    //check if someone won diagonally
    if ((board[0][0] == playerSign) && (board[1][1] == playerSign) && (board[2][2] == playerSign)) {
        return true;
    }
    if ((board[2][0] == playerSign) && (board[1][1] == playerSign) && (board[0][2] == playerSign)) {
        return true;
    }

    return false;
}

bool checkDraw(vector<string>& board) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j] == '_') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        vector<string> board(3, "");
        for(int i = 0; i<3; i++) {
            cin>>board[i];
        }
        bool xWon = checkIfWon(board, 'X');
        bool oWon = checkIfWon(board, 'O');

        if ((!checkMoveCountValid(board)) || (xWon && oWon)) {
            cout<<"3\n";
        } else if (xWon || oWon || checkDraw(board)) {
            cout<<"1\n";
        } else {
            cout<<"2\n";
        }
    }
}