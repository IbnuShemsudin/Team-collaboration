#include <iostream>
using namespace std;

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