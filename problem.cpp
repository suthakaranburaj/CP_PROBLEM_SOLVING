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
void print_1d_array(vector<int>&arr){
    int n = arr.size();
    cout<<"[";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

vector<int> build_prime_prefix(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= max_num; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> prefix(max_num + 1, 0);
    for (int i = 1; i <= max_num; ++i) {
        prefix[i] = prefix[i - 1] + (is_prime[i] ? 1 : 0);
    }

    return prefix;
}

vector<int> count_primes_in_ranges(vector<vector<int>>& queries) {
    int max_val = 0;
    for (auto& q : queries) {
        max_val = max(max_val, q[1]);
    }

    vector<int> prefix = build_prime_prefix(max_val);

    vector<int> result;
    for (auto& q : queries) {
        int L = q[0];
        int R = q[1];
        int count = prefix[R] - prefix[L - 1];
        result.push_back(count);
    }

    return result;
}
void solve() {
    vector<vector<int>> queries = { {2, 5}, {4, 7}, {1, 10} };
    vector<int> result = count_primes_in_ranges(queries);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
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