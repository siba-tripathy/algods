#include<iostream>
#include<string>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int turn=1; turn<=t; turn++) {
        string num;
        cin>>num;
        long long int sum_of_digits = 0;
        for(int i=0; i<num.size(); i++) {
            sum_of_digits+=num[i]-'0';
        }
        int num_to_add = 9-sum_of_digits%9;
        char char_to_add = char('0'+num_to_add);
        if (num_to_add != 0) {
            int first_greater = num.size();
            for(int i=0; i<num.size(); i++) {
                int val =num[i]-'0';
                if(val>num_to_add) {
                    first_greater = i;
                    break;
                }
            }
            num.insert(first_greater, 1, char_to_add);
        }
        cout<<"Case #"<<turn<<": "<<num<<endl;
    }
}