#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    int size;
    int capacity;
    int *arr;

    MinHeap(int s) {
        this->size = 0;
        this->capacity = s;
        arr = new int[capacity];
    }

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    void insert(int v) {
        if (this->size == this->capacity) {
            cout << "The Min Heap is Full" << endl;
            return;
        }

        this->arr[size] = v;
        int k = this->size;
        this->size++;

        while (k != 0 && this->arr[parent(k)] > this->arr[k]) {
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

    int getMin() {
        if (this->size == 0) return INT_MAX;
        return this->arr[0];
    }

    void heapify(int index) {
        int lc = leftChild(index);
        int rc = rightChild(index);

        int smallest = index;
        if (lc < this->size && this->arr[smallest] > this->arr[lc]) {
            smallest = lc;
        }
        if (rc < this->size && this->arr[smallest] > this->arr[rc]) {
            smallest = rc;
        }

        if (smallest != index) {
            swap(this->arr[index], this->arr[smallest]);
            heapify(smallest);
        }
    }

    void changeKey(int index, int v) {
        this->arr[index] = v;
        while (index != 0 && this->arr[parent(index)] > this->arr[index]) {
            swap(this->arr[parent(index)], this->arr[index]);
            index = parent(index);
        }
    }

    int extractMin() {
        if (this->size == 0) {
            return INT_MAX;
        }

        if (this->size == 1) {
            this->size--;
            return this->arr[0];
        }

        int mini = this->arr[0];
        this->arr[0] = this->arr[this->size - 1];
        this->size--;

        heapify(0);
        return mini;
    }

    void deleteKey(int index) {
        if (index >= this->size) {
            cout << "Index is greater than size of Heap" << endl;
            return;
        }
        changeKey(index, INT_MIN);
        extractMin();
    }
};

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

int main(){

    return 0;
}