#include<iostream>
#include<vector>
#include<set>

using namespace std;

//https://www.lintcode.com/problem/909/
//leetcode free mirror
//got AC
//same recursion backtracking but impl tricky with edge cases

bool isTravelPossible(set<int> &passedPositions, int lastAdded, int nextPosition) {
    if (lastAdded == 0 || lastAdded ==5 || nextPosition==5) {
        return true;
    }
    if (lastAdded%2 == 0 && (lastAdded+nextPosition==10)) {
        if (passedPositions.find(5) == passedPositions.end()) {
            return false;
        }
    }
    if (lastAdded%2 == 1 && nextPosition%2==1 && nextPosition != 5) {
        if (passedPositions.find((lastAdded+nextPosition)/2) == passedPositions.end()) {
            return false;
        }
    }
    return true;
}

int getCombos(set<int> &passedPositions, int minLength, int maxLength, int lastAdded) {
    if (passedPositions.size() == maxLength) {
        return 0;
    }
    int possibilities = 0;
    for(int i = 1; i<=9; i++) {
        if ((passedPositions.find(i) == passedPositions.end()) && isTravelPossible(passedPositions, lastAdded, i)) {
            passedPositions.insert(i);
            if(passedPositions.size() >= minLength) {
                possibilities++;
            }
            possibilities+=getCombos(passedPositions, minLength, maxLength, i);
            passedPositions.erase(i);
        }
    }
    return possibilities;
}

int main() {
    int m, n;
    cin>>m>>n;
    set<int> set;
    cout<<getCombos(set, m, n, 0);
}