#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> arr;

public:
    void enqueue(int x) {
        arr.push_back(x);
    }

    int dequeue() {
        if (arr.empty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int frontElement = arr[0];
        arr.erase(arr.begin());
        return frontElement;
    }

    int peek() {
        if (arr.empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr.front();
    }

    bool isEmpty() {
        return arr.empty();
    }

    void display() {
        if (arr.empty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int num : arr)
            cout << num << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front Element: " << q.peek() << endl;
    return 0;
}
