#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
    if ((a%2==0 && b%2==0) || (a%2 == 1 && b%2 ==1)) {
        return a<b;
    }
    else if(a%2==0 && b%2==1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    vector<int> arr{2, 5, 3, 1, 12, 9, 6};
    sort(arr.begin(), arr.end(), compare);

    for (int x: arr) {
        cout<<x<<" ";
    }
}