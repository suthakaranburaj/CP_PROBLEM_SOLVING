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

const int MOD = 998244353;
const long long inv2 = 499122177;
class ArrayStack {
public:
    int *arr;
    int size;
    int top;
    
    ArrayStack(int size) {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
        // cout << "Stack Created Successfully!" << endl;
    }

    void push(int x) {
        if (this->top == this->size - 1) { 
            // cout << "Stack is full" << endl;
        } else {
            this->top++;
            arr[this->top] = x;
            // cout << x << " Inserted Successfully!" << endl;
        }
    }

    int pop() {
        if (this->top == -1) {
            // cout << "No data in stack!" << endl;
            return -1;
        } else {
            return this->arr[this->top--];
        }
    }

    int topElement() {
        if (this->top == -1) {
            // cout << "No data in stack!" << endl;
            return -1;
        }
        return this->arr[this->top];
    }

    bool isEmpty() {
        return this->top == -1;
    }
};

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

typedef long long ll;

ll g(ll M) {
    if (M == 0) return 0;
    ll res = 0;
    while (M > 0) {
        int b = 0;
        while ((1LL << (b+1)) - 1 <= M) 
            b++;
        ll comp = (1LL << b) - 1;
        if (M == comp) {
            res += b * (1LL << (b-1));
            break;
        } else {
            res += b * (1LL << (b-1)) + (1LL << b);
            M -= (1LL << b);
        }
    }
    return res;
}

ll f(ll N) {
    if (N == 1) return 0;
    if ((N & (N+1)) == 0) {
        int b = 0;
        ll t = N+1;
        while (t > 1) {
            b++;
            t /= 2;
        }
        return b * (1LL << (b-1)) - 1;
    } else {
        int b = 0;
        while ((1LL << (b+1)) <= N) 
            b++;
        ll M = 1LL << b;
        ll R = N - M;
        ll c = (N == M) ? M+1 : M;
        ll cost_L = b * (1LL << (b-1)) - 1;
        return cost_L + g(R) + c;
    }
}

void solve() {
    ll N;
    cin>>N;
    cout<<f(N)<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int a = 1;
    cin>>a;
    while(a--) {
        solve();
    }
    return 0;
}