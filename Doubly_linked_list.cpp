#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int data;
};

Node* head = nullptr;

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n*....Main Menu*****\n";
        cout << "\nChoose one option from the following list...\n";
        cout << "\n1.Insert in beginning\n2.Insert at last\n3.Insert at any random location";
        cout << "\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data";
        cout << "\n7.Search\n8.Show\n9.Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last();
                break;
            case 6:
                deletion_specified();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
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
    int item;
    if (!ptr) {
        cout << "\nOVERFLOW" << endl;
    } else {
        cout << "\nEnter Item value: ";
        cin >> item;
        ptr->data = item;
        if (!head) {
            ptr->next = nullptr;
            ptr->prev = nullptr;
            head = ptr;
        } else {
            ptr->next = head;
            ptr->prev = nullptr;
            head->prev = ptr;
            head = ptr;
        }
        cout << "\nNode inserted\n";
    }
}

void insertion_last() {
    Node* ptr = new Node();
    int item;
    if (!ptr) {
        cout << "\nOVERFLOW" << endl;
    } else {
        cout << "\nEnter value: ";
        cin >> item;
        ptr->data = item;
        if (!head) {
            ptr->next = nullptr;
            ptr->prev = nullptr;
            head = ptr;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = nullptr;
        }
        cout << "Node inserted\n";
    }
}

void insertion_specified() {
    Node* ptr = new Node();
    int item, loc;
    if (!ptr) {
        cout << "\nOVERFLOW" << endl;
    } else {
        cout << "Enter the value: ";
        cin >> item;
        ptr->data = item;
        cout << "Enter the location: ";
        cin >> loc;
        Node* temp = head;
        for (int i = 1; i < loc; i++) {
            temp = temp->next;
            if (!temp) {
                cout << "\nThere are less than " << loc << " elements" << endl;
                return;
            }
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next) temp->next->prev = ptr;
        temp->next = ptr;
        cout << "\nNode inserted\n";
    }
}

void deletion_beginning() {
    if (!head) {
        cout << "\nUNDERFLOW" << endl;
    } else if (!head->next) {
        delete head;
        head = nullptr;
        cout << "\nNode deleted\n";
    } else {
        Node* ptr = head;
        head = head->next;
        head->prev = nullptr;
        delete ptr;
        cout << "\nNode deleted\n";
    }
}

void deletion_last() {
    if (!head) {
        cout << "\nUNDERFLOW" << endl;
    } else if (!head->next) {
        delete head;
        head = nullptr;
        cout << "\nNode deleted\n";
    } else {
        Node* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->prev->next = nullptr;
        delete ptr;
        cout << "\nNode deleted\n";
    }
}

void deletion_specified() {
    int loc;
    cout << "\nEnter the location node to be deleted: ";
    cin >> loc;
    Node* ptr = head;
    while (ptr && ptr->data != loc) {
        ptr = ptr->next;
    }
    if (!ptr) {
        cout << "\nNode not found\n";
    } else if (!ptr->next) {
        if (ptr->prev) ptr->prev->next = nullptr;
        delete ptr;
        cout << "\nNode deleted\n";
    } else {
        Node* temp = ptr->next;
        ptr->next = temp->next;
        if (temp->next) temp->next->prev = ptr;
        delete temp;
        cout << "\nNode deleted\n";
    }
}

void display() {
    if (!head) {
        cout << "Nothing to print" << endl;
    } else {
        Node* ptr = head;
        cout << "\nPrinting values...\n";
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

void search() {
    if (!head) {
        cout << "\nEmpty List\n";
    } else {
        int item, i = 1;
        bool found = false;
        cout << "\nEnter item to search: ";
        cin >> item;
        Node* ptr = head;
        while (ptr) {
            if (ptr->data == item) {
                cout << "\nItem found at location " << i << endl;
                found = true;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        if (!found) {
            cout << "\nItem not found\n";
        }
    }
}
