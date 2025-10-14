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
    
    ArrayQueue st(5);
    st.push(10);
    st.push(20);
    cout << "rear: " << st.rearElement() << endl;
    st.push(30);
    cout << "Pop: " << st.pop() << endl;
    cout << "rear after pop: " << st.rearElement() << endl;

    if (st.isEmpty()) cout << "Queue is empty\n";
    else cout << "Queue is not empty\n";
    st.print_queue();
    return 0;
}