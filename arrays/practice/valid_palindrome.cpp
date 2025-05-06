#include<bits/stdc++.h>

using namespace std;

// Lc : Easy-Med : Very Good : https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r) {
            if (s[l] != s[r]) {
                break;
            }
            l++;
            r--;
        }
        if (l>=r) {
            return true;
        }
        int newl = l+1;
        int newr = r;
        while(newl<newr) {
            if (s[newl] != s[newr]) {
                break;
            }
            newl++;
            newr--;
        }
        if (newl>=newr) {
            return true;
        }
        newl = l;
        newr =r-1;
        while(newl<newr) {
            if(s[newl] != s[newr]) {
                break;
            }
            newl++;
            newr--;
        }
        if (newl>=newr) {
            return true;
        }
        return false;
    }
};