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

class ArrayQueue {
public:
    int *arr;
    int size;
    int rear;
    int front;

    ArrayQueue(int size) {
        this->size = size;
        this->arr = new int[size];
        this->rear = -1;
        this->front = -1;
        cout << "Queue Created Successfully!" << endl;
    }

    void push(int x) {
        if (this->rear == size - 1) { // FIXED
            cout << "Queue is full!" << endl;
            return;
        } else if (this->rear == -1 && this->front == -1) {
            this->rear = this->front = 0;
        } else {
            this->rear++;
        }
        arr[this->rear] = x;
        cout << "Data added successfully!" << endl;
    }

    int pop() {
        if (this->front == -1 && this->rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        } else if (this->front == this->rear) {
            int val = arr[front];
            arr[front] = -1;
            this->front = -1;
            this->rear = -1;
            cout << "Data popped successfully!" << endl;
            return val;
        } else {
            int val = arr[front];
            arr[front] = -1;
            this->front++;
            cout << "Data popped successfully!" << endl;
            return val;
        }
    }

    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return this->arr[this->rear];
    }

    bool isEmpty() {
        return this->rear == -1 && this->front == -1;
    }

    void print_queue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = this->front; i <= this->rear; i++) {
            cout << "Element " << i << " = " << this->arr[i] << endl;
        }
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }
        return waterTrapped;
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
void solve() {

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