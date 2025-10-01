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
#include <bits/stdc++.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_1d_array(vector<int>&arr){
    int n = arr.size();
    // cout<<"[";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void input_1d_array(vector<int>&arr,int &n,int &k){
    cin>>n;
    cin>>k;
    arr.resize(n);
    for(int i = 0 ;i<n; i++){
        cin>>arr[i];
    }
}
void input_1d_array_leetcode(vector<int>&arr,int n){
    cin>>n;
    string s;
    cin >> s;

    int num = 0;
    bool inNumber = false, isNegative = false;

    for (char c : s) {
        if (c == '-') {
            isNegative = true;
        } 
        else if (isdigit(c)) {
            num = num * 10 + (c - '0');
            inNumber = true;
        } 
        else {
            if (inNumber) {
                if (isNegative) num = -num;
                arr.push_back(num);
                num = 0;
                inNumber = false;
                isNegative = false;
            }
        }
    }
}

class MaxHeap {
public:
    int size;
    int capacity;
    int *arr;

    MaxHeap(int s) {
        this->size = 0;
        this->capacity = s;
        arr = new int[capacity];
    }

    ~MaxHeap() {
        delete[] arr;
    }

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    void insert(int v) {
        if (this->size == this->capacity) {
            cout << "The Max Heap is Full" << endl;
            return;
        }

        this->arr[size] = v;
        int k = this->size;
        this->size++;

        while (k != 0 && this->arr[parent(k)] < this->arr[k]) {
            swap(this->arr[parent(k)], this->arr[k]);
            k = parent(k);
        }
    }

    bool isEmpty() {
        return this->size == 0;
    }

    int heapSize() {
        return this->size;
    }

    int getMax() {
        if (this->size == 0) return INT_MIN;
        return this->arr[0];
    }

    void heapify(int index) {
        int lc = leftChild(index);
        int rc = rightChild(index);

        int largest = index;
        if (lc < this->size && this->arr[largest] < this->arr[lc]) {
            largest = lc;
        }
        if (rc < this->size && this->arr[largest] < this->arr[rc]) {
            largest = rc;
        }

        if (largest != index) {
            swap(this->arr[index], this->arr[largest]);
            heapify(largest);
        }
    }

    void changeKey(int index, int v) {
        this->arr[index] = v;
        while (index != 0 && this->arr[parent(index)] < this->arr[index]) {
            swap(this->arr[parent(index)], this->arr[index]);
            index = parent(index);
        }
    }

    int extractMax() {
        if (this->size == 0) {
            return INT_MIN;
        }

        if (this->size == 1) {
            this->size--;
            return this->arr[0];
        }

        int maximum = this->arr[0];
        this->arr[0] = this->arr[this->size - 1];
        this->size--;

        heapify(0);
        return maximum;
    }

    void deleteKey(int index) {
        if (index >= this->size) {
            cout << "Index is greater than size of Heap" << endl;
            return;
        }
        changeKey(index, INT_MAX);
        extractMax();
    }
};
/*
    Happy Coding
*/
int kth_largest_element(vector<int>&arr,int n,int &k){
    MaxHeap mh(n);
    for(int i = 0;i<n; i++){
        mh.insert(arr[i]);
    }
    int parent = 0;
    int ans = -1;
    for (int i = 0; i < k; i++) {
        ans = mh.extractMax();
    }
    return ans;
}
void solve() {
    vector<int>arr;
    int n;
    int k;
    input_1d_array(arr,n,k);
    int ans = kth_largest_element(arr,n,k);
    // print_1d_array(arr);
    cout<<ans<<endl;
    
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