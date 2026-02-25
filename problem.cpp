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
    // cin>>n;
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
    vector<int>arr1;
    string arr2;
    int n,k;
    cin>>n>>k;
    input_1d_array(arr1,n);
    // input_1d_array(arr2,n);
    cin>>arr2;
    
    vector<int>temp;
    int n1 = arr1.size();
    for(int i = 0;i<n1;i++){
        int t_size = temp.size();
        if(t_size < k){
            if(arr2[i] != '1'){
                temp.push_back(arr1[i]);
            }
        }
        else{
            if(arr2[i] != '1'){
                sort(temp.begin(),temp.end());
                int largest = temp[t_size-1];
                if(largest > arr1[i]){
                    temp.pop_back();
                    temp.push_back(arr1[i]);
                }
            }
        }
    }

    if(temp.size() < k){
        cout<<"-1"<<endl;
        return;
    }
    int ans = 0;
    for(int i = 0;i<k;i++){
        ans += temp[i];
    }
    cout<<ans<<endl;
    return;
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