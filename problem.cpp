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
#include <bits/stdc++.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_1d_array(vector<int>&arr){
    int n = arr.size();
    // cout<<"[";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void input_1d_array(vector<int>&arr,int n){
    cin>>n;
    arr.resize(n);
    for(int i = 0 ;i<n; i++){
        cin>>arr[i];
    }
}
void input_1d_array_leetcode(vector<int>&arr,int n){
    cin>>n;
    string s;
    cin >> s;

    int num = 0;
    bool inNumber = false, isNegative = false;

    for (char c : s) {
        if (c == '-') {
            isNegative = true;
        } 
        else if (isdigit(c)) {
            num = num * 10 + (c - '0');
            inNumber = true;
        } 
        else {
            if (inNumber) {
                if (isNegative) num = -num;
                arr.push_back(num);
                num = 0;
                inNumber = false;
                isNegative = false;
            }
        }
    }
}
/*
    Happy Coding
*/
void solve() {
    int N;
    cin >> N;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 1) cnt1++;
        else if (x == 2) cnt2++;
        else cnt3++;
    }

    long long result = 0;
    result += 1LL * cnt1 * (cnt1 - 1) / 2;
    result += 1LL * cnt1 * cnt2;
    result += 1LL * cnt2 * cnt3;

    cout << result << endl;
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