#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &arr)
    {
        // code here
        int element = arr[0];
        arr[0] = arr[arr.size() - 1];
        for (int i = 1; i < arr.size(); i++)
        {
            int temp = arr[i];
            arr[i] = element;
            element = temp;
        }
    }
};