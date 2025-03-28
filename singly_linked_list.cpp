#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the linked list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Destructor to free the memory
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert at the beginning
    void beginsert() {
        int item;
        cout << "Enter value: ";
        cin >> item;
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        cout << "Item inserted at the beginning.\n";
    }

    // Insert at the end
    void lastinsert() {
        int item;
        cout << "Enter value: ";
        cin >> item;
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Item inserted at the end.\n";
    }

    // Insert at a specific position
    void random_insert() {
        int loc, item;
        cout << "Enter value: ";
        cin >> item;
        cout << "Enter position: ";
        cin >> loc;

        Node* newNode = new Node(item);
        if (loc == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Item inserted at position " << loc << ".\n";
            return;
        }

        Node* temp = head;
        for (int i = 1; i < loc - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Item inserted at position " << loc << ".\n";
    }

    // Delete from the beginning
    void begin_delete() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Item deleted from the beginning.\n";
    }

    // Delete from the end
    void last_delete() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Only node of the list deleted.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        Node* prev = head;
        while (prev->next != temp) {
            prev = prev->next;
        }
        prev->next = nullptr;
        delete temp;
        cout << "Item deleted from the end.\n";
    }

    // Delete from a specific position
    void random_delete() {
        int loc;
        cout << "Enter position to delete: ";
        cin >> loc;

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (loc == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Item deleted from position " << loc << ".\n";
            return;
        }

        Node* temp = head;
        for (int i = 1; i < loc - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Item deleted from position " << loc << ".\n";
    }

    // Search for an element
    void search() {
        int item;
        cout << "Enter item to search: ";
        cin >> item;

        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == item) {
                cout << "Item found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Item not found.\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function with a menu
int main() {
    SinglyLinkedList list;
    int choice = 0;

    while (choice != 9) {
        cout << "\nChoose one option from the following list:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Specific Position\n";
        cout << "7. Search\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: list.beginsert(); break;
            case 2: list.lastinsert(); break;
            case 3: list.random_insert(); break;
            case 4: list.begin_delete(); break;
            case 5: list.last_delete(); break;
            case 6: list.random_delete(); break;
            case 7: list.search(); break;
            case 8: list.display(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
