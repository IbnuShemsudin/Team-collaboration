#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}


// Traverse the list forward
    void traverseForward() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtPosition(15, 1);

    cout << "Forward traversal: ";
    dll.traverseForward();  // Output: 10 15 20

    cout << "Backward traversal: ";
    dll.traverseBackward(); //
    dll.deleteFromBeginning();
    dll.traverseForward();  // Output: 15 20

    dll.deleteFromEnd();
    dll.traverseForward();  // Output: 15

    dll.insertAtEnd(25);
    dll.insertAtEnd(30);
    dll.deleteFromPosition(1);
    dll.traverseForward();  // Output: 15 30

    return 0;
}

// Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;

    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->prev->next = nullptr;
        delete last;
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (position == 0) {
            deleteFromBeginning();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        delete current;

    }
    // Traverse the list backward
    void traverseBackward() const {
        if (head == nullptr) return;
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        while (last != nullptr) {
            cout << last->data << " ";
            last = last->prev;
        }
        cout << endl;
    }
