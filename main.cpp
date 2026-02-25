#include <iostream>
#include <string>
#include "list.h"
using namespace std;

// ------------------------------------------------------------
// Jay Patel jpatel89
// Lab 4 main:
// Read each line: integer1 integer2
// Convert both to digit-lists
// Add them
// Print the sum
// ------------------------------------------------------------

int main() {
    string s1, s2;

    // Input format: two space-separated integers per line
    while (cin >> s1 >> s2) {
        // Build lists (least significant digit at head)
        List a = List::fromString(s1);
        List b = List::fromString(s2);

        // Add lists (returns NEW heap list)
        List* sum = List::addLists(a, b);

        // Output only the final sum
        sum->printNumber();

        // free the returned list
        delete sum;
    }

    return 0;
}
