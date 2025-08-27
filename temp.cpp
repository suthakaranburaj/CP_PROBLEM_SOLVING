/*
    author : suthakar_09
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define sz(a) (int)(a).size()
class ArrayStack {
public:
    int *arr;
    int size;
    int top;
    
    ArrayStack(int size) {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
        // cout << "Stack Created Successfully!" << endl;
    }

    void push(int x) {
        if (this->top == this->size - 1) { 
            // cout << "Stack is full" << endl;
        } else {
            this->top++;
            arr[this->top] = x;
            // cout << x << " Inserted Successfully!" << endl;
        }
    }

    int pop() {
        if (this->top == -1) {
            // cout << "No data in stack!" << endl;
            return -1;
        } else {
            return this->arr[this->top--];
        }
    }

    int topElement() {
        if (this->top == -1) {
            // cout << "No data in stack!" << endl;
            return -1;
        }
        return this->arr[this->top];
    }

    bool isEmpty() {
        return this->top == -1;
    }
};

void print_1d_array(vector<int>&arr){
    int n = arr.size();
    cout<<"[";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    Happy Coding
*/
void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int a = 1;
    cin>>a;
    while(a--) {
        solve();
    }
    return 0;
}