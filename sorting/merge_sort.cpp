#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int l1, int r1, int l2, int r2) {
    int i = l1;
    int j = l2;
    vector<int> merged_array;
    while(i<=r1 && j<=r2) {
        if (arr[i]<=arr[j]) {
            merged_array.push_back(arr[i]);
            i++;
        }
        else {
            merged_array.push_back(arr[j]);
            j++;
        }
    }

    while(i<=r1) {
        merged_array.push_back(arr[i]);
        i++;
    }

    while(j<=r2) {
        merged_array.push_back(arr[j]);
        j++;
    }

    for (int x =0; x < merged_array.size(); x++) {
        arr[l1+x] = merged_array[x];
    }

    for(int x: arr){
            cout<<x<<" ";
    }
    cout<<endl;
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (r-l>=1) {
        //find mid
        int mid = (l + r )/2;
        //divide
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        //merge(conquer)
        merge(arr, l, mid, mid+1, r);
    }
}

int main(){
    int n;
    vector<int> arr{12, 11, 3, 2, 5, 7, 9, 6, 3, 4, 10};
    merge_sort(arr, 0, arr.size()-1);
    cout<<endl<<"Sorted Array is: ";
    for (int x: arr) {
        cout<<" "<<x; 
    }
}