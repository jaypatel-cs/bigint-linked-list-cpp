#include "list.h"
#include <iostream>
using namespace std;
List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
    // Destructor must free all nodes to pass Valgrind
    clear();
}

void List::clear() {
    // Delete every node in the list
    Node* cur = head;
    while (cur != nullptr) {
        Node* next = cur->next; // save next before deleting
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
}

void List::copyFrom(const List& other) {
    // Copy nodes in the same order so the new list is identical
    Node* cur = other.head;
    while (cur != nullptr) {
        push_back(cur->digit);  // push_back preserves order
        cur = cur->next;
    }
}

List::List(const List& other) : head(nullptr), tail(nullptr) {
    // Copy constructor: make a deep copy (new nodes)
    copyFrom(other);
}

List& List::operator=(const List& other) {
    // Assignment operator: prevent self-assignment bugs
    if (this == &other) {
        return *this;
    }

    // Free old nodes, then copy the other list
    clear();
    copyFrom(other);
    return *this;
}

void List::push_front(int digit) {
    // New node points to current head
    Node* n = new Node(digit, head);
    head = n;

    // If list was empty, tail must also point to the new node
    if (tail == nullptr) {
        tail = head;
    }
}

void List::push_back(int digit) {
    // Create a new node that will become the new tail
    Node* n = new Node(digit, nullptr);

    if (tail == nullptr) {
        // Empty list: head and tail both become n
        head = n;
        tail = n;
    } else {
        // Non-empty list: attach to tail, then move tail
        tail->next = n;
        tail = n;
    }
}

Node* List::getHead() const {
    return head;
}

List List::fromString(const string& s) {
    List result;

    // head must be least significant digit.
    // If s = "123":
    // push_front(1) -> [1]
    // push_front(2) -> [2]->[1]
    // push_front(3) -> [3]->[2]->[1] 
    for (int i = 0; i < (int)s.size(); i++) {
        int digit = s[i] - '0';  // convert char '0'..'9' to int 0..9
        result.push_front(digit);
    }

    return result;
}

List* List::addLists(const List& a, const List& b) {
    // create a NEW list and return it (caller deletes it)
    List* sum = new List();

    Node* pa = a.getHead();
    Node* pb = b.getHead();
    int carry = 0;

    // Add like paper addition:
    // - read current digits
    // - add with carry
    // - store ones digit
    // - update carry
    while (pa != nullptr || pb != nullptr || carry != 0) {
        int da = (pa != nullptr) ? pa->digit : 0; // if list ended, digit is 0
        int db = (pb != nullptr) ? pb->digit : 0;

        int total = da + db + carry;
        int outDigit = total % 10; // digit to store
        carry = total / 10;        // carry to next step (0 or 1 usually)

        // We are adding from least significant to most significant.
        // Using push_back keeps the least significant digit at the HEAD,
        // because the first digit we produce is the ones place.
        sum->push_back(outDigit);

        // Move forward if nodes exist
        if (pa != nullptr) pa = pa->next;
        if (pb != nullptr) pb = pb->next;
    }

    return sum;
}

void List::printNumber() const {
    // The list stores digits backwards (ones digit at head),
    // but output must be normal (most significant first).
    //
    // Beginner approach: build a temporary reversed list,
    // then print it forward.

    List reversed;

    // Reverse by pushing digits to the front of a new list
    Node* cur = head;
    while (cur != nullptr) {
        reversed.push_front(cur->digit);
        cur = cur->next;
    }

    // Print the reversed list in normal forward order
    Node* p = reversed.getHead();
    while (p != nullptr) {
        cout << p->digit;
        p = p->next;
    }
    cout << "\n";
}
