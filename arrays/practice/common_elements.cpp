#include<bits/stdc++.h>

using namespace std;

// GFG : Easy : V Good : https://www.geeksforgeeks.org/problems/common-elements1132/1

class Solution
{
public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3)
    {
        // Code Here
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        while (i < arr1.size())
        {
            int element = arr1[i];
            // cout<<arr1[i]<<" "<<arr2[j]<<" "<<arr3[k]<<endl;
            while (j < arr2.size() && arr2[j] < arr1[i])
            {
                j++;
            }
            while (k < arr3.size() && arr3[k] < arr1[i])
            {
                k++;
            }
            if (j < arr2.size() && arr2[j] == arr1[i] && k < arr3.size() && arr3[k] == arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            while (i < arr1.size() && element == arr1[i])
            {
                i++;
            }
        }
        return ans;
    }
};