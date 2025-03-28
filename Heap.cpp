#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

public:
    MinHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) heapifyDown(i);
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<int> arr = {10, 20, 15, 30, 40};
    MinHeap heap(arr);

    heap.printHeap();

    heap.insert(5);
    heap.printHeap();

    heap.deleteMin();
    heap.printHeap();

    return 0;
}
