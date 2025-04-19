#include <bits/stdc++.h>
using namespace std;

// gfg: easy : AC : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        int cur_max_from_right = arr[arr.size() - 1];
        vector<int> ans;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            cur_max_from_right = max(cur_max_from_right, arr[i]);
            if (arr[i] >= cur_max_from_right)
            {
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--)
    {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.leaders(a);

        // Print the result in the required format
        if (result.empty())
        {
            cout << "[]"; // Print empty brackets if no leaders are found
        }
        else
        {
            for (int i = 0; i < result.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends