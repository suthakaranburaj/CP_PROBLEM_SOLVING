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
        cout<<arr[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}
/*
    Happy Coding
*/
void solve() {
    int n;
    cin>>n;
    vector<int> small_divisors, large_divisors;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            small_divisors.push_back(i);
            if (i != n / i) {
                large_divisors.push_back(n / i);
            }
        }
    }

    reverse(large_divisors.begin(), large_divisors.end());
    small_divisors.insert(small_divisors.end(), large_divisors.begin(), large_divisors.end());
    print_1d_array(small_divisors);
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