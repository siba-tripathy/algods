#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//https://www.spoj.com/problems/ABCDEF/

vector<int> getCombos(vector<int>& arr, string form) {
    vector<int> combos;

    for(int i =0; i<arr.size(); i++) {
        int a = arr[i];
        for(int j = 0; j<arr.size(); j++) {
            int b = arr[j];
            for(int k = 0; k<arr.size(); k++) {
                int c = arr[k];
                if (form == "LHS")
                    combos.push_back(a*b + c);
                else if (form == "RHS" && c!= 0)
                    combos.push_back(c*(a+b));
            }
        }
    }
    return combos;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> lhsCombos = getCombos(arr, "LHS");
    vector<int> rhsCombos = getCombos(arr, "RHS");

    sort(rhsCombos.begin(), rhsCombos.end());

    int ans = 0;
    for(int i=0; i<lhsCombos.size(); i++) {
        auto lb = lower_bound(rhsCombos.begin(), rhsCombos.end(), lhsCombos[i]);
        auto ub = upper_bound(rhsCombos.begin(), rhsCombos.end(), lhsCombos[i]);
        ans += ub - lb;
    }
    cout<<ans<<endl;
}