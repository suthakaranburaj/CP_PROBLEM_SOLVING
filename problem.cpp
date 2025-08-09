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
    cout << "Hello" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    string S;
    cin >> S;
    int n = S.size();
    vector<int> pos;
    for (int i = 0; i < n; ++i)
        if (S[i] == 't') pos.push_back(i);
    double max_rate = 0.0;
    int m = pos.size();
    for (int a = 0; a < m; ++a) {
        for (int b = a + 2; b < m; ++b) {
            int len = pos[b] - pos[a] + 1;
            int cnt_t = b - a + 1;
            double rate = double(cnt_t - 2) / double(len - 2);
            max_rate = max(max_rate, rate);
        }
    }
    cout << fixed << setprecision(17) << max_rate << '\n';
    return 0;
}