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

void input_1d_array(vector<int>&arr,int &n){
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void input_1d_array_leetcode(vector<int>&arr,int n){
    cin>>n;
    string s;
    cin >> s;

    arr.clear();
    arr.reserve(n);

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
void heapify(int index,int n,vector<int>&arr){
    int lc = 2*index+1;
    int rc = 2*index+2;

    int smallest = index;
    if (lc < n && arr[smallest] < arr[lc]) {
        smallest = lc;
    }
    if (rc < n && arr[smallest] < arr[rc]) {
        smallest = rc;
    }

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapify(smallest,n,arr);
    }
}
void convert_min_to_max_heap(vector<int>&arr, int n){
    for(int i = n/2 - 1;i>=0 ; i--){
        heapify(i,n,arr);
    }
}
void solve() {
    vector<int>arr;
    int n;
    input_1d_array(arr,n);
    convert_min_to_max_heap(arr,n);
    print_1d_array(arr);
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