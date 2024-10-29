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
