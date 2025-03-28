#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> arr; // Vector-based stack

public:
    void push(int x) {
        arr.push_back(x);
    }

    int pop() {
        if (arr.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int topElement = arr.back();
        arr.pop_back();
        return topElement;
    }

    int peek() {
        if (arr.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() {
        return arr.empty();
    }

    void display() {
        if (arr.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.display();
    
    cout << "Popped: " << s.pop() << endl;
    s.display();
    
    cout << "Top Element: " << s.peek() << endl;
    return 0;
}
