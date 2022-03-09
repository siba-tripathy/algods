#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

//https://leetcode.com/problems/lru-cache/submissions/
//AC
//IMP count is faster than m.find() == m.end() - changed my ans from TLE to AC


class LRUCache {
	int cap;
    list<pair<int, int> > key_value;
    unordered_map<int, list<pair<int, int> >::iterator> m;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        //IMP count is faster than m.find() == m.end() - changed my ans from TLE to AC
        if(!m.count(key)) {
        	return -1;
        }

        auto p = *m[key];
        key_value.erase(m[key]);
        key_value.push_back(p);
        m[key] = --key_value.end();                //only way of doing it since cant do -1 on interators

        return p.second;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
        	key_value.erase(m[key]);
        }

        pair<int, int> p(key, value);
        key_value.push_back(p);
        m[key] = --key_value.end();

        if (key_value.size()>cap) {
            m.erase(key_value.begin()->first);
        	key_value.erase(key_value.begin());
            
        }
    }
};