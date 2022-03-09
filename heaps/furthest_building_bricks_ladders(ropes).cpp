//https://leetcode.com/problems/furthest-building-you-can-reach


//AC
//Using Min Heap
struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        priority_queue<int, vector<int>, compare > min_heap;
        for(i=0; i<heights.size()-1; i++) {
            if (heights[i+1]<=heights[i]) {
                continue;
            } else {
                int diff = heights[i+1]-heights[i];
                min_heap.push(diff);
                if(min_heap.size()>ladders) {
                    bricks-=min_heap.top();
                    min_heap.pop();
                }
                if (bricks<0) {
                    break;
                }
            }
            cout<<bricks<<endl;
        }
        return i;
        
    }
};


//AC
//Using Maxx Heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        priority_queue<int> max_heap;
        int max_heap_sum = 0;
        for(i=0; i<heights.size()-1; i++) {
            if (heights[i+1]<=heights[i]) {
                continue;
            } else {
                int diff = heights[i+1]-heights[i];
                max_heap.push(diff);
                max_heap_sum+=diff;
                if(max_heap_sum > bricks) {
                    if(ladders) {
                        ladders--;
                        max_heap_sum-=max_heap.top();
                        max_heap.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        return i;
        
    }
};
