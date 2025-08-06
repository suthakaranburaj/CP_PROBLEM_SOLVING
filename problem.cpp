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
void solve() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int total = 5 * (a1 - a2) + (b1 - b2);
    if (total < 0 || total % 6 != 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
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