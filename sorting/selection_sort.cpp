#include<vector>
#include<iostream>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int j;
        int min_position = i;
        for (j = i+1; j<n; j++) {
            if (arr[min_position] > arr[j])
                min_position = j;
        }
        swap(arr[min_position], arr[i]);
        for(int x: arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    vector<int> arr{12, 11, 3, 2, 5, 7, 9, 6, 3, 4, 10};
    selection_sort(arr);
    cout<<endl<<"Sorted Array is: ";
    for (int x: arr) {
        cout<<" "<<x; 
    }
}