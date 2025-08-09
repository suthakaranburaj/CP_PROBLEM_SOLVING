/* author : suthakar_09 */
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define sz(a) (int)(a).size()

void print_1d_array(vector<int>& arr) {
    int n = arr.size();
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

/* Happy Coding */
void solve() {
    cout << "Hello" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;

    int N;
    string S;
    cin >> N >> S;

    if (N >= 3) {
        string ans = S.substr(N - 3, 3);
        if (ans == "tea") {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        cout << "No";
    }

    return 0;
}
