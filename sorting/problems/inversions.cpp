#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// counting the inversions in an array
// https://www.codechef.com/UASS001/problems/CINV
long long int merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> merged(r-l+1, 0);
    int latest = 0;
    int i=l, j=mid+1;
    long long int reverse_pairs = 0;
    while(i<=mid && j<=r) {
        if(arr[i]<=arr[j]) {
            merged[latest++] = arr[i];
            i++;
        } else {
            merged[latest++] = arr[j];
            reverse_pairs+=mid-i+1;
            j++;
        }
    }
    while(i<=mid) {
        merged[latest++] = arr[i];
        i++;
    }
    while(j<=r) {
        merged[latest++] = arr[j];
        j++;
    }
    for(int index=0; index<merged.size(); index++) {
        arr[l+index] = merged[index];
    }
    return reverse_pairs;
}

long long int merge_sort(vector<int>& arr, int l, int r) {
    if(r>l){
        int mid = (r+l)/2;
        long long int left_reverse_pairs = merge_sort(arr, l, mid);
        long long int right_reverse_pairs = merge_sort(arr, mid+1, r);
        long long int reverse_pairs = merge(arr, l, mid, r);
        return left_reverse_pairs + right_reverse_pairs + reverse_pairs;
    } else {
        return 0;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        long long int reversed_pairs = merge_sort(arr, 0, n-1);
        cout<<reversed_pairs<<endl;
    }
}
// int main() {
//     int t = 1;
//     //cin>>t;
//     while(t--) {
//         int n;
//         //cin>>n;
//         //vector<int> arr;
//         //for(int i = 0; i< n; i++) {
//         //  int a;
//         //  cin>>a;
//         //  arr.push_back(a);    
//         //}
//         vector<int> arr{ 6, 2, 7, 3, 9, 1, 2};
//         int reverse_pairs = merge_sort(arr, 0, arr.size()-1);
//         cout<<"sorted array is";
//         for(int x: arr) {
//             cout<<x<<" ";
//         }
//         cout<<endl<<"Number of reversed pairs are: "<< reverse_pairs<<endl;
//     }
//     return 0;
// }