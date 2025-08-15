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

class ArrayStack {
public:
    int *arr;
    int size;
    int top;
    
    ArrayStack(int size) {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
    }

    void push(int x) {
        if (this->top != this->size - 1) {
            this->top++;
            arr[this->top] = x;
        }
    }

    int pop() {
        if (this->top == -1) {
            return -1;
        } else {
            return this->arr[this->top--];
        }
    }

    int topElement() {
        if (this->top == -1) {
            return -1;
        }
        return this->arr[this->top];
    }

    bool isEmpty() {
        return this->top == -1;
    }
};

bool check_operator_precedence(char op1, char op2) {
    auto precedence = [](char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };
    if (precedence(op1) == precedence(op2)) {
        if (op1 == '^') return false;
        else return true;
    }
    return precedence(op1) > precedence(op2);
}

void convert_infix_to_postfix(string &input, string &output) {
    int n = input.length();
    ArrayStack st(n);
    int i = 0;

    while (i < n) {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9')) {
            output.push_back(input[i]);
        }
        else if (input[i] == '(') {
            st.push(input[i]);
        }
        else if (input[i] == ')') {
            while (!st.isEmpty() && st.topElement() != '(') {
                output.push_back(st.topElement());
                st.pop();
            }
            if (!st.isEmpty() && st.topElement() == '(')
                st.pop();
        }
        else {
            while (!st.isEmpty() && st.topElement() != '(' &&
                   check_operator_precedence(st.topElement(), input[i])) {
                output.push_back(st.topElement());
                st.pop();
            }
            st.push(input[i]);
        }
        i++;
    }

    while (!st.isEmpty()) {
        output.push_back(st.topElement());
        st.pop();
    }
}

void solve() {
    string output = "";
    string input = "";
    cin >> input;
    convert_infix_to_postfix(input, output);
    cout << output << endl;
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
