#include<iostream>
#include<stack>

using namespace std;

class min_max_stack {
public:
	stack<int> s;
	stack<int> maxi;
	stack<int> mini;



	min_max_stack() {}
	void push(int x) {
		if (s.empty()) {
			s.push(x);
			maxi.push(x);
			mini.push(x);
		} else {
			maxi.push(max(maxi.top(), x));
			mini.push(min(mini.top(), x));
			s.push(x);
		}
	}

	int pop() {
        if(!s.empty()) {
		int x = s.top();
		maxi.pop();
		mini.pop();
		s.pop();
		return x;
        } else {
            return -1;
        }
	}

	int top() {
		return s.top();
	}

	bool empty() {
		return s.empty();
	}

	int size() {
		return s.size();
	}

	int maxim() {
		return maxi.top();
	}

	int minim() {
		return mini.top();
	}
};

int main() {
	min_max_stack sta;
	sta.push(2);
	sta.push(5);
	sta.push(1);
	sta.push(20);

	cout<<sta.maxim()<<endl;
    cout<<sta.minim()<<endl;
    sta.pop();
    cout<<sta.maxim()<<endl;
	cout<<sta.minim();
}