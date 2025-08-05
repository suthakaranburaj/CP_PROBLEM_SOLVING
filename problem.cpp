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

/*
    Happy Coding
*/
void solve() {
    int n;
    cin>>n;
    int arr[n];
    int result = 0;
    for(int i = 0;i<n; i++){
        cin>>arr[i];    
        result ^= arr[i];
    }
    cout<<result<<endl;
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