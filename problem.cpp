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

void print_1d_array(vector<int>&arr){
    int n = arr.size();
    cout<<"[";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

class ArrayStack {
public:
    string *arr;
    int size;
    int top;
    
    ArrayStack(int size) {
        this->size = size;
        this->arr = new string[size];
        this->top = -1;
    }

    void push(string x) {
        if (this->top != this->size - 1) {
            this->top++;
            arr[this->top] = x;
        }
    }

    string pop() {
        if (this->top == -1) {
            return "";
        } else {
            return this->arr[this->top--];
        }
    }

    string topElement() {
        if (this->top == -1) {
            return "";
        }
        return this->arr[this->top];
    }

    bool isEmpty() {
        return this->top == -1;
    }
};

void convert_prefix_to_postfix(string &input, string &output) {
    int n = input.length();
    ArrayStack st(n);
    int i = n - 1;

    while (i >= 0) {
        char c = input[i];
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            string s(1, c);
            st.push(s);
        }
        else{
            //for operator
            string str1 = st.pop();
            string str2 = st.pop();
            string new_str = str1 + str2 + string(1, c);
            // cout<<i<<" "<<new_str<<endl;
            st.push(new_str);
        }
        i--;
    }
    output = st.topElement();
}

void solve() {
    string output = "";
    string input = "";
    cin >> input;
    if(input == ""){
        return;
    }
    convert_prefix_to_postfix(input, output);
    cout << output << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int a;
    cin >> a;
    while (a--) {
        solve();
    }
    return 0;
}
