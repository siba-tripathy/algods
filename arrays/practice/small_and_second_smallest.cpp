#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> array = {3, 4, 5, 5, 6, 1, 1, 3};

    int smallest = INT_MAX;
    int smallest2 = INT_MAX;
    //cout<<array.size();

    for (int i = 0; i <array.size(); i++) {
        if (array[i] < smallest) {
            smallest2 = smallest;
            smallest = array[i];
        } else if (array[i] > smallest && array[i] < smallest2) {
            smallest2= array[i];
        }
    }
    if (smallest != INT_MAX && smallest2 != INT_MAX) {
        cout<<smallest<<" "<<smallest2;
    }
    return 0;
}