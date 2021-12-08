#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/sudoku-solver/submissions/
//AC

bool isSafe(vector<vector<char> >& board, int i, int j, int num) {
	for (int y = 8; y>=0; y--) {
		if (board[i][y] == '0' + num) {
			return false;
		}
	}
	for(int x = 8; x>=0; x--) {
		if(board[x][j] == '0' + num) {
			return false;
		}
	}
	int smallBoardXAxis = i/3;
	int smallBoardYAxis = j/3;

	for(int x = smallBoardXAxis*3; x<(smallBoardXAxis+1)*3; x++) {
		for(int y = smallBoardYAxis*3; y<(smallBoardYAxis+1)*3; y++) {
			if (board[x][y] == '0' + num) {
				return false;
			}
		}
	}
    return true;
}

bool isFixed(vector<vector<char> >& inputBoard, int i, int j) {
	if (inputBoard[i][j] == '.') {
		return false;
	}
    return true;
}

bool solveSudoku(vector<vector<char> >& inputBoard, vector<vector<char> >& ansBoard, int i, int j) {
    if (i > 8) {
        return true;
    }
	if (isFixed(inputBoard, i, j)) {
		return solveSudoku(inputBoard, ansBoard, (j==8 ? i+1 : i), (j+1)%9);
	}


    // recusion on 2-d array: strcutre important
	bool isNumPossibleAtIJ = false;
	for(int num = 1; num <10; num++) {
		if (isSafe(ansBoard, i, j, num)) {                     //prune
			ansBoard[i][j] = '0' + num;
			bool isPossible = solveSudoku(inputBoard, ansBoard, (j==8 ? i+1 : i), (j+1)%9);
			if (isPossible) {
				return true;
			} else {
				ansBoard[i][j] = '.';                          //reset
			}
		}
	}
    return false;
}

void printSudoku(vector<vector<char> >& board) {
	for(int i = 0; i<9; i++) {
		for(int j = 0; j<9; j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	vector<vector<char> > puzzle  = vector<vector<char> >(9, vector<char>(9, '.'));
	for(int i =0; i< 9; i++) {
		for(int j = 0; j<9; j++) {
			cin>>puzzle[i][j];
		}
	}
	vector<vector<char> > ansBoard = vector<vector<char> >(puzzle);

	solveSudoku(puzzle, ansBoard, 0, 0);
    printSudoku(ansBoard);

}