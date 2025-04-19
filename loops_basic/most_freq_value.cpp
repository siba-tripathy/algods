#include <bits/stdc++.h>
using namespace std;

// CC: AC : good easy : https://www.codechef.com/problems/MAXCOUNT

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> freq;
        int most_freq_value = 0, max_freq = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (freq.find(a) == freq.end())
            {
                freq[a] = 1;
            }
            else
            {
                freq[a]++;
            }

            if (freq[a] > max_freq || freq[a] == max_freq && a < most_freq_value)
            {
                max_freq = freq[a];
                most_freq_value = a;
            }
        }
        cout << most_freq_value << " " << max_freq << endl;
    }
}
