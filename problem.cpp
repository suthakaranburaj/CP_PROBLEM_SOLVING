/*
    author : suthakaranburaj
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

void check_nth_bit(int &n ,int &i){
    string ans = ((n & 1<<i-1) ? "Yes" : "No");
    cout<<ans<<endl;
}
void solve() {
    int n,i;
    cin>>n>>i;
    // cout<<endl;
    check_nth_bit(n,i);
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
    // cout<<endl;
    while(a--) {
        solve();
    }
    
    return 0;
}