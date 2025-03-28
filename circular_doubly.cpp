#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 7) {
        cout << "\n*Main Menu*****\n";
        cout << "\nChoose one option from the following list...\n";
        cout << "1. Insert in Beginning\n2. Insert at last\n3. Delete from Beginning\n4. Delete from last\n5. Search\n6. Show\n7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                deletion_beginning();
                break;
            case 4:
                deletion_last();
                break;
            case 5:
                search();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Please enter a valid choice.." << endl;
        }
    }
    return 0;
}

void insertion_beginning() {
    Node* ptr = new Node();
    if (!ptr) {
        cout << "\nOVERFLOW" << endl;
        return;
    }

    int item;
    cout << "\nEnter Item value: ";
    cin >> item;

    ptr->data = item;

    if (!head) {
        head = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    cout << "\nNode inserted\n";
}

void insertion_last() {
    Node* ptr = new Node();
    if (!ptr) {
        cout << "\nOVERFLOW" << endl;
        return;
    }

    int item;
    cout << "\nEnter value: ";
    cin >> item;

    ptr->data = item;

    if (!head) {
        head = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = head;
        head->prev = ptr;
    }
    cout << "\nNode inserted\n";
}

void deletion_beginning() {
    if (!head) {
        cout << "\nUNDERFLOW" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        cout << "\nNode deleted\n";
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "\nNode deleted\n";
    }
}

void deletion_last() {
    if (!head) {
        cout << "\nUNDERFLOW" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        cout << "\nNode deleted\n";
    } else {
        Node* ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
        delete ptr;
        cout << "\nNode deleted\n";
    }
}

void display() {
    if (!head) {
        cout << "\nNothing to print" << endl;
        return;
    }

    Node* ptr = head;
    cout << "\nPrinting values:\n";
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

void search() {
    if (!head) {
        cout << "\nEmpty List\n";
        return;
    }

    int item, i = 1, flag = 1;
    cout << "\nEnter item which you want to search: ";
    cin >> item;

    Node* ptr = head;
    do {
        if (ptr->data == item) {
            cout << "Item found at location " << i << endl;
            flag = 0;
            break;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != head);

    if (flag) {
        cout << "Item not found\n";
    }
}
