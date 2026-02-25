# List-Based Integer Addition (C++)

## Overview
Adds two arbitrarily large non-negative integers using a singly linked list, where each node stores one digit.
The least significant digit is stored at the head of the list.

## Features
- Builds a digit-list from a number string
- Adds two digit-lists with carry (like paper addition)
- Outputs the sum in normal order
- Implements the Rule of Three (copy constructor, assignment operator, destructor)
- Manual memory management (new/delete) designed to be Valgrind-clean

## File Structure
- `list.h` / `list.cpp`: linked list implementation + bigint addition logic
- `main.cpp`: reads pairs of integers and prints their sums

## How to Run
Compile:
```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp list.cpp -o add_bigints
