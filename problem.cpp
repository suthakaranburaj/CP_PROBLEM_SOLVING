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

const int MAXA = 1e7 + 5;
vector<int> freq(MAXA, 0);

void input_1d_array(vector<int>&arr,int &n,int &max_no){
    cin>>n;
    arr.resize(n);
    for(int i = 0 ;i<n; i++){
        int temp = 0;
        cin>>temp;
        arr[i] = temp;
        max_no = max(max_no, temp);
        freq[temp]++;
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
bool no_divisible(vector<int> &arr,int &num){
    for(int i = 0;i<arr.size();i++){
        if(arr[i]%num == 0){
            return false;
        }
    }
    return true;
}
int find_ans(vector<int> &arr,int &n,int &min_no){
    for(int i = min_no;i>=5;i--){
        if(no_divisible(arr,i)){
            return i;
        }
    }
    return -1;
}
void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int M = *max_element(A.begin(), A.end());
    int count_M = 0;
    bool found_less = false;
    for (int x : A) {
        if (x == M) count_M++;
        if (x < M - 1) found_less = true;
    }
    if (count_M >= 2) {
        cout << M - 1 << endl;
    } else {
        if (found_less) {
            cout << M - 1 << endl;
        } else {
            cout << M - 2 << endl;
        }
    }
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