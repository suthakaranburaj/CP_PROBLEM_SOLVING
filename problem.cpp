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

/*
    Happy Coding
*/

//also find 1st and 2nd min
void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    int min_ans = INT_MAX;
    int min_1 = INT_MAX;
    int min_2 = INT_MAX;

    for(int i = 0;i<n;i++){
        cin>>arr[i];
        if (arr[i] < min_1) {
            min_2 = min_1;
            min_1 = arr[i];
        } else if (arr[i] < min_2) {
            min_2 = arr[i];
        }
        if(i == 0) continue;
        int temp = arr[i]/2+arr[i-1];
        min_ans = min(min_ans , temp);
    }
    int final_ans = min(min_ans,min_1+min_2);
    cout<<final_ans<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int a;
    cin>>a;
    while(a--) {
        solve();
    }
    return 0;
}