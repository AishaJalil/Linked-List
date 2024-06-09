#include <iostream>
using namespace std;

// Node class for doubly circular linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(0), prev(0) {}
};

// Doubly Circular Linked List class
class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() : head(0) {}

    // Function to add a node to the doubly circular linked list
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == 0) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = last;
            last->next = newNode;
        }
    }

    // Overload the assignment operator to convert to a singly linked list
    DoublyCircularLinkedList& operator=(const DoublyCircularLinkedList& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        // Clear the current list
        while (head != 0) {
            Node* temp = head->next;
            delete head;
            head = temp;
            if (head == other.head) {
                break;
            }
        }

        // Copy elements from the other list to create a singly linked list
        Node* otherCurrent = other.head;
        while (otherCurrent != 0) {
            addNode(otherCurrent->data);
            otherCurrent = otherCurrent->next;
            if (otherCurrent == other.head) {
                break;
            }
        }

        return *this;
    }

    // Function to display the doubly circular linked list
    void display() {
        if (head == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << " (Circular)" << endl;
    }

    // Destructor to free memory
    ~DoublyCircularLinkedList() {
        while (head != 0) {
            Node* temp = head->next;
            delete head;
            head = temp;
            if (head == head->next) {
                head = 0;
            }
        }
    }
};

int main() {
    DoublyCircularLinkedList list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);

    DoublyCircularLinkedList list2;
    list2.addNode(4);
    list2.addNode(5);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list2 = list1; // Assign list1 to list2

    

    return 0;
}
