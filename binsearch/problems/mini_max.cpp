#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//https://www.spoj.com/problems/BOOKS1/
//Not Accepted Till Now

bool checkIfMaxPerScriberSuffices(vector<int>& bookPages, int max_per_scriber, int scribers) {
    int last_book_allocated = 0, current_scriber_load = 0;
    for(int i=0; i<bookPages.size(); i++) {
        if(scribers == 0) 
            break;
        if (current_scriber_load + bookPages[i] < max_per_scriber) {   //MAX
            current_scriber_load += bookPages[i];
        } else {
            scribers--;
            if(scribers == 0)
                break;
            current_scriber_load = bookPages[i];
        }
        last_book_allocated = i+1;
    }

    return (last_book_allocated == bookPages.size());
}

void printAllocation(vector<int>& bookPages, int max_per_scriber, int numberOfScribers) {
    int current_scriber_load = 0, scribers_left = numberOfScribers;
    vector<int> booksPerScriber = vector<int>(numberOfScribers, 0);
    for(int i = bookPages.size() - 1; i >= 0; i--) {
        if (i+1 == scribers_left) {
            booksPerScriber[scribers_left-1]++;
            scribers_left--;
        }
        else if (current_scriber_load + bookPages[i] <= max_per_scriber) {
            booksPerScriber[scribers_left-1]++;
            current_scriber_load += bookPages[i];
        } else {
            scribers_left--;
            current_scriber_load = 0;
            i++;
        }
    }
    
    int bookCount = 0;
    for(int i=0; i<booksPerScriber.size(); i++) {
        //cout<<booksForCurrentScriber<< " ";
        for (int j=0; j<booksPerScriber[i]; j++) {
            cout<<bookPages[bookCount++]<<" ";
        }
        if(i<booksPerScriber.size()-1)
            cout<<"/ ";
    };
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, s, sumOfPages = 0, maxBookPages = 0;
        cin>>n>>s;

        vector<int> bookPages = vector<int>(n, 0);
        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            bookPages[i] = a;
            sumOfPages += a;
            maxBookPages = max(maxBookPages, a);
        }

        int min_pages = maxBookPages, max_pages = sumOfPages, ans;

        while(min_pages<=max_pages) {
            int max_per_scriber = (min_pages+max_pages)/2;

            if(checkIfMaxPerScriberSuffices(bookPages, max_per_scriber, s)) {
                ans=max_per_scriber, max_pages=max_per_scriber-1;     //MINI
            } else {
                min_pages = max_per_scriber+1;
            }
        }
        printAllocation(bookPages, ans, s);
        cout<<endl;
    }
}