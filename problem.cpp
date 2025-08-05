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

// Sieve of Eratosthenes
vector<bool> find_prime_nums(int max_num) {
    vector<bool> prime(max_num + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= max_num; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_num = *max_element(all(arr));
    vector<bool> is_prime = find_prime_nums(max_num);

    // Store all primes up to max_num
    vector<int> primes;
    for (int i = 2; i <= max_num; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        vector<int> factors;
        
        for (int prime : primes) {
            while (num % prime == 0) {
                factors.push_back(prime);
                num /= prime;
            }
            if (num == 1) break;
        }
        
        if (num > 1) factors.push_back(num);  // For remaining prime > sqrt(n)
        ans.push_back(factors);
    }

    // Print result
    for (const auto& vec : ans) {
        cout << "[ ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
