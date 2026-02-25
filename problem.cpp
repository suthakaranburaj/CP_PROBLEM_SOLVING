/*
    author : suthakar_09
*/
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
    Happy Coding
*/
void solve() {
    int A,B,X,Y;
    cin>>A>>B>>X>>Y;

    int ans = B;
    while(A >= X){
        A = A - X;
        ans = ans + Y;
    }
    ans = ans + A;
    cout<<ans<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif    
    int a = 1;
    cin>>a;
    while(a--) {
        solve();
    }
    return 0;
}