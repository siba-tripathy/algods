#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//given n people, and freindship pairs (i, j) are friends
//a person goes to party if atleast k friends of her/his go to the party
//find max number of people that can go to the party


//works perfectly checked with pulkit chhabra's lecture examples - DS1 C++

int main() {
    int n, f, k;
    cin>>n>>f>>k;

    vector<int> nums(n, 0);
    vector<vector<int> > adj(n);
    vector<bool> going(n, true);

    for(int i=0; i<f; i++) {
        int f1, f2;
        cin>>f1>>f2;
        nums[f2-1]++;
        nums[f1-1]++;
        adj[f1-1].push_back(f2-1);
        adj[f2-1].push_back(f1-1);
    }
    queue<int> q;

    for(int i=0; i<n; i++) {
        if(nums[i]<k) {
            going[i]=false;
            q.push(i);
        }
    }

    while(!q.empty()) {                                //n times
        int out = q.front();
        q.pop();
        for(int i = 0; i<adj[out].size(); i++) {        // 2f times max(f or m -> no of friendships)
            if (going[adj[out][i]] == true) {           //only check those whore are going to party as of now
                nums[adj[out][i]]--;                    //impact on the friend
                if (nums[adj[out][i]] < k) {            //check if they will now be not going
                    going[adj[out][i]] = false;         //ensure that elements go into queue only once (when they move from going to not going)
                    q.push(adj[out][i]);
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        if (going[i]) {
            cout<<i+1<<" ";
        }
    }
}