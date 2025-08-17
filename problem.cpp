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
class Solution {
public:
    vector<int> nextGreatestElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;         

        for (int i = 0; i < n; i++) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                ans[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return ans;
    }
};

void print_1d_array(vector<int>&arr){
    for(int a : arr){
        cout<<a<<" ";
    }
}
void solve() {
    int n;
    cin>>n;
    vector<int>input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    Solution sol;
    vector<int> output = sol.nextGreatestElements(input);
    print_1d_array(output);
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
