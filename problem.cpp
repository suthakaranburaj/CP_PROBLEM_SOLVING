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

int divide(int dividend, int divisor) {
    // Step 1: Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Step 2: Convert to long long to avoid overflow
    long long a = abs((long long)dividend); // Convert to positive
    long long b = abs((long long)divisor);

    long long result = 0;

    // Step 3: Bitwise subtraction logic
    // Start from 31 down to 0 to check the highest power of 2 multiple
    for (int i = 31; i >= 0; i--) {
        if ((a >> i) >= b) {
            a -= (b << i);        // Subtract b * 2^i from a
            result += (1LL << i); // Add 2^i to result
        }
    }

    // Step 4: Apply the sign
    // If dividend and divisor have different signs, make result negative
    if ((dividend < 0) != (divisor < 0)) {
        result = -result;
    }

    // Step 5: Return the final result as int
    return (int)result;
}

void solve() {
    int a, b;
    cin>>a>>b;
    int result = divide(a,b);
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