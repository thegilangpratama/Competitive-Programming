#include <iostream>

// STILL NEED TO LEARN THIS

// Use the standard namespace as requested
using namespace std;

// Definition of a Node in the singly linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Class to manage the linked list operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    // --- Insertion Operations ---

    // 1. At Beginning: Insert a new node at the start of a linked list.
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
    }

    // 2. At the End: Insert a new node at the end of the linked list.
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << val << " at the end." << endl;
    }

    // 3. At Specific Position: Insert a new node at a specific position (1-based index).
    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position " << pos << " is out of bounds." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " at position " << pos << "." << endl;
    }

    // --- Deletion Operations ---

    // 4. From Beginning: Delete a node from the start of a linked list.
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning." << endl;
        delete temp;
    }

    // 5. From the End: Delete a node at the end of a linked list.
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from the end." << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    // 6. A Specific Node: Delete a node from a specific position (1-based index).
    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Position " << pos << " is out of bounds." << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << pos << "." << endl;
        delete nodeToDelete;
    }

    // --- Traversal Operation ---

    // 7. Traversal: Traverse the linked list from start to end.
    void traverse() {
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Main function to demonstrate all operations
int main() {
    LinkedList list;

    cout << "--- Demonstration of Linked List Operations ---\n" << endl;

    // --- Insertion ---
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.traverse(); // Expected: 10 -> 20 -> 40 -> 50 -> nullptr

    list.insertAtPosition(30, 3);
    list.traverse(); // Expected: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
    cout << endl;

    // --- Deletion ---
    list.deleteFromBeginning();
    list.traverse(); // Expected: 20 -> 30 -> 40 -> 50 -> nullptr

    list.deleteFromEnd();
    list.traverse(); // Expected: 20 -> 30 -> 40 -> nullptr

    list.deleteAtPosition(2); // Deletes node at position 2 (value 30)
    list.traverse(); // Expected: 20 -> 40 -> nullptr

    return 0;
}