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

class ArrayStack {
public:
    string *arr;
    int size;
    int top;
    
    ArrayStack(int size) {
        this->size = size;
        this->arr = new string[size];
        this->top = -1;
    }

    void push(string x) {
        if (this->top != this->size - 1) {
            this->top++;
            arr[this->top] = x;
        }
    }

    string pop() {
        if (this->top == -1) {
            return "";
        } else {
            return this->arr[this->top--];
        }
    }

    string topElement() {
        if (this->top == -1) {
            return "";
        }
        return this->arr[this->top];
    }

    bool isEmpty() {
        return this->top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void convert_infix_to_prefix(string &input, string &output) {
    reverse(input.begin(), input.end());
    for (char &c : input) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    int n = input.length();
    ArrayStack st(n);
    string postfix = "";

    for (int i = 0; i < n; i++) {
        char c = input[i];
        if (isalnum(c)) {
            postfix.push_back(c);
        }
        else if (c == '(') {
            st.push("(");
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.topElement() != "(") {
                postfix += st.pop();
            }
            if (!st.isEmpty()) st.pop(); // pop '('
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.topElement()[0]) > precedence(c)) {
                postfix += st.pop();
            }
            st.push(string(1, c));
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    reverse(postfix.begin(), postfix.end());
    output = postfix;
}

void solve() {
    string output = "";
    string input = "";
    cin >> input;
    if (input == "") return;
    convert_infix_to_prefix(input, output);
    cout << output << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    
    int a;
    cin >> a;
    while (a--) {
        solve();
    }
    return 0;
}
