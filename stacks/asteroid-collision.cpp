#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//https://leetcode.com/problems/asteroid-collision/submissions/
//AC


vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for(int i =0; i<n; i++) {
            if (s.empty() || asteroids[i]>0) {
                s.push(asteroids[i]);
            } else {
                while(!s.empty() && s.top()*asteroids[i] < 0 && abs(s.top()) < abs(asteroids[i]))  { //checking if both have different signs
                    s.pop();
                }
                if (s.empty() || s.top()*asteroids[i] > 0) {
                    s.push(asteroids[i]);
                } else if (abs(s.top()) == abs(asteroids[i])){
                    s.pop();
                }
            }
        }
        int ans_size = s.size();
        vector<int> ans(ans_size);
        int pos = ans_size - 1;
        while(!s.empty()) {
            int x = s.top();
            ans[pos]=x;
            s.pop();
            pos--;
        }
        return ans;
    }

int main() {
  //take input
}