#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//https://codeforces.com/problemset/problem/1251/D
//AC

bool compare(int a, int b) {
    return a>b;
}

int is_median_possible(vector<int>& l, vector<int>& r, int median, long long int max_salary) {
    //return -1 if median is too low
    //return 0 if median is a possible salary
    //return 1 if median is too big

    long long int n = l.size(), lesser = 0, greater = 0, greater_or_equal=0, amount_paid = 0;
    vector<int> mid_values;
    
    for(int i = 0; i<n; i++) {
        if(r[i]< median) {
            amount_paid += l[i];
            lesser++;
        } else if (l[i] > median) {
            greater++;
            greater_or_equal++;
            amount_paid += l[i];
        } else {
            mid_values.push_back(l[i]);
        }
    }

    if(lesser >= (n+1)/2 ) {
        return 1;
    } else if (greater >= (n+1)/2) {
        return -1;
    }

    sort(mid_values.begin(), mid_values.end(), compare);

    for(int i=0; i<mid_values.size(); i++) {        
        if (greater_or_equal >= (n+1)/2) {
            amount_paid += mid_values[i];
        } else {
            greater_or_equal++;
            amount_paid+= median;
        }
        
    }

    if (greater_or_equal < (n+1)/2) 
        return -1;
    if (max_salary >= amount_paid)
        return 0;
    else
        return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long int n, s;
        cin>>n>>s;
        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for(int i=0; i<n; i++) {
            cin>>l[i] >> r[i];
        }

        //range of the median will be between l_median and r_median as those are the two extreme distributions
        // lowest extreme : give every body l[i], highest extre : give everybody r[i]

        vector<int> l_med(l.begin(), l.end());
        vector<int> r_med(r.begin(), r.end());
        sort(l_med.begin(), l_med.end());
        sort(r_med.begin(), r_med.end());

        int l_median = l_med[n/2];
        int r_median = r_med[n/2];
        int ans;

        while(l_median <= r_median) {
            int mid = (l_median + r_median)/2;
            int is_median_value_possible = is_median_possible(l, r, mid, s);

            if(is_median_value_possible == 0) {
                ans = mid;
                l_median = mid + 1;
            } else if (is_median_value_possible < 0){
                l_median = mid + 1;
            } else {
                r_median = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
}