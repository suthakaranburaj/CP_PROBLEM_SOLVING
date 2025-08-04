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
    int a,b;
    cin>>a>>b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout<<"a:"<<a<<"b:"<<b<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}