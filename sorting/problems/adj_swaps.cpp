#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// counting the inversions in an array
// 
long long int merge(vector<int>& arr, int l, int mid, int r, vector<int>& swaps) {
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
            for(int index=mid; index>=i; index--) {
                swaps.push_back(index);
            }
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

long long int merge_sort(vector<int>& arr, int l, int r, vector<int>& swaps) {
    if(r>l){
        int mid = (r+l)/2;
        long long int left_reverse_pairs = merge_sort(arr, l, mid, swaps);
        long long int right_reverse_pairs = merge_sort(arr, mid+1, r, swaps);
        long long int reverse_pairs = merge(arr, l, mid, r, swaps);
        return left_reverse_pairs + right_reverse_pairs + reverse_pairs;
    } else {
        return 0;
    }
}

int main(){
    
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        vector<int> swaps;
        long long int reversed_pairs = merge_sort(arr, 0, n-1, swaps);
        cout<<reversed_pairs<<endl;
        for(int index = 0; index<swaps.size(); index++) {
            cout<<swaps[index]<<" ";
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