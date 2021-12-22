#include<iostream>
#include<vector>

using namespace std;

//great question
//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
//AC

int getConditionalLCSSize(vector<int>& arr, vector<int>& brr, int k) {
	int n = arr.size();
	int m = brr.size();

	vector<vector<int> > lcsLength(n+1, vector<int>(m+1, 0));
	vector<vector<int> > replaceCount(n+1, vector<int>(m+1, 0));

	for(int i = 1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {

			if (arr[i-1] == brr[j-1]) {
				lcsLength[i][j] = 1+lcsLength[i-1][j-1];
                replaceCount[i][j] = replaceCount[i-1][j-1];
			}
			else {
                //delete ith element of arr
				lcsLength[i][j] = lcsLength[i-1][j];
                replaceCount[i][j] = replaceCount[i-1][j];

                //insert an element in arr
                if (lcsLength[i][j] <  lcsLength[i][j-1] || (lcsLength[i][j] ==  lcsLength[i][j-1] && replaceCount[i][j] > replaceCount[i][j-1]) ) {
                    lcsLength[i][j] = lcsLength[i][j-1];
                    replaceCount[i][j] = replaceCount[i][j-1];
                }

                //replace
				if (replaceCount[i-1][j-1] <k && (lcsLength[i][j] < 1+ lcsLength[i-1][j-1] || (lcsLength[i][j] == 1+ lcsLength[i-1][j-1] && replaceCount[i][j] > 1+ replaceCount[i-1][j-1])) ) {
					replaceCount[i][j] = 1+ replaceCount[i-1][j-1];
					lcsLength[i][j] = 1+ lcsLength[i-1][j-1];
				}
			}
		}
	}

//     cout<<"lcs Lngth matrix:"<<endl;
//     for(int i = 0; i<n+1; i++) {
// 		for(int j=0; j<m+1; j++) {
//             cout<<lcsLength[i][j]<<" ";
//         }
//         cout<<endl;
//         }

// cout<<"replaceCount matrix:"<<endl;
//         for(int i = 0; i<n+1; i++) {
// 		for(int j=0; j<m+1; j++) {
//             cout<<replaceCount[i][j]<<" ";
//         }
//         cout<<endl;
//         }

	return lcsLength[n][m];
}

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> arr(n);
	vector<int> brr(m);

	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}

	for(int i = 0; i<m; i++) {
		cin>>brr[i];
	}

    cout<<getConditionalLCSSize(arr, brr, k);

}