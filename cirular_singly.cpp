#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void beginsert();
void lastinsert();
void begin_delete();
void last_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 7) {
        cout << "\n....Main Menu....\n";
        cout << "\nChoose one option from the following list...\n";
        cout << "1. Insert in beginning\n2. Insert at last\n3. Delete from beginning\n4. Delete from last\n5. Search for an element\n6. Show\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                begin_delete();
                break;
            case 4:
                last_delete();
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

void beginsert() {
    Node* ptr = new Node();
    if (!ptr) {
        cout << "\nOVERFLOW\n";
        return;
    }

    int item;
    cout << "\nEnter the node data: ";
    cin >> item;

    ptr->data = item;
    if (!head) {
        head = ptr;
        ptr->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
    cout << "\nNode inserted\n";
}

void lastinsert() {
    Node* ptr = new Node();
    if (!ptr) {
        cout << "\nOVERFLOW\n";
        return;
    }

    int item;
    cout << "\nEnter Data: ";
    cin >> item;

    ptr->data = item;
    if (!head) {
        head = ptr;
        ptr->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = head;
    }
    cout << "\nNode inserted\n";
}

void begin_delete() {
    if (!head) {
        cout << "\nUNDERFLOW\n";
        return;
    }

    Node* ptr = head;
    if (head->next == head) {
        head = nullptr;
        delete ptr;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head = head->next;
        delete ptr;
    }
    cout << "\nNode deleted\n";
}

void last_delete() {
    if (!head) {
        cout << "\nUNDERFLOW\n";
        return;
    }

    Node* ptr = head;
    Node* preptr = nullptr;

    if (head->next == head) {
        head = nullptr;
        delete ptr;
    } else {
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = head;
        delete ptr;
    }
    cout << "\nNode deleted\n";
}

void search() {
    if (!head) {
        cout << "\nEmpty List\n";
        return;
    }

    int item, i = 1, flag = 1;
    cout << "\nEnter searching item: ";
    cin >> item;

    Node* ptr = head;
    do {
        if (ptr->data == item) {
            cout << "\nItem found at location " << i << endl;
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

void display() {
    if (!head) {
        cout << "\nNothing to print\n";
        return;
    }

    Node* ptr = head;
    cout << "\nPrinting values: ";
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
