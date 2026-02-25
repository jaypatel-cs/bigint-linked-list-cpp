#ifndef LIST_H
#define LIST_H

#include <string>

// ------------------------------------------------------------
// Adding List-Based Integers
// Each node stores ONE digit (0-9).
// The HEAD node is the least significant digit (ones place).
// Example: 123 is stored as: [3] -> [2] -> [1] -> NULL
// ------------------------------------------------------------

// A single linked-list node
struct Node {
    int digit;     // one digit (0-9)
    Node* next;    // pointer to next node

    Node(int d, Node* n = nullptr) : digit(d), next(n) {}
};

// A small list class that owns and deletes its nodes
class List {
private:
    Node* head; // least significant digit
    Node* tail; // helps add to the end in O(1)

    // helper functions for memory management (Rule of 3)
    void clear();                    // delete all nodes in this list
    void copyFrom(const List& other); // deep copy nodes from another list

public:
    List();              // create empty list

    // Rule of 3: because we use new/delete
    ~List();             // destructor frees nodes (no leaks)
    List(const List& other);
    List& operator=(const List& other);

    // Basic inserts
    void push_front(int digit); // insert at head
    void push_back(int digit);  // insert at tail

    // Read-only access to head pointer (needed for addition)
    Node* getHead() const;

    // Build a list from a number string (ex: "123")
    static List fromString(const std::string& s);

    // Add two digit-lists and return a NEW list on the heap
    // Caller must delete it.
    static List* addLists(const List& a, const List& b);

    // Print the number in normal order (most significant first)
    void printNumber() const;
};

#endif
