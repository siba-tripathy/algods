#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/longest-palindromic-subsequence

//gave correct test case ans. checked and same as sanket. but still TLE, dont know why
int findMaxLPSTopDown(string s, vector<vector<int> >& lps, int i, int j) {
    if (i>j) {return 0;}
	if (lps[i][j] != 0) {
		return lps[i][j];
	}
	if(i==j) {return lps[i][j] = 1;}
	if (s[i] == s[j] && j == i+1) { return lps[i][j] = 2;}
	else if (s[i] == s[j]) {
		return lps[i][j] = 2 + findMaxLPSTopDown(s, lps, i+1, j-1);
	}
	else {
		return lps[i][j] = max(findMaxLPSTopDown(s, lps, i+1, j), findMaxLPSTopDown(s, lps, i, j-1));
	}
}


//bottom up
//GOT AC
int findMaxLPSBU(string s) {
    int n = s.size();
    vector<vector<int> > lps(n,  vector<int>(n, 0));
    
    //fill base case
    for(int i=0; i<n; i++) {
        lps[i][i] = 1;
    }

    for(int len = 2; len<=n; len++) {
        for(int i=0; i<=n-len; i++) {
            int j = i+len-1;
            if (s[i] == s[j] && j == i+1) {
                lps[i][j] = 2;
            } else if (s[i] == s[j]) {
                lps[i][j] = 2+lps[i+1][j-1];
            } else {
                lps[i][j] = max(lps[i+1][j], lps[i][j-1]);
            }
        }
    }

    return lps[0][n-1];

}

int main(){
	string s;
	cin>>s;
	vector<vector<int> > lps(s.size(), vector<int>(s.size(), 0));
	cout<<findMaxLPSBU(s);
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            cout<<lps[i][j]<<" ";
        }
        cout<<endl;
    }
}