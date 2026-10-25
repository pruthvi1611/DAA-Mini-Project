// searching.h - Linear and Binary search
// Each function returns the position (index) of the student, or -1 if not found.
#pragma once
#include "student.h"

// Linear Search - O(n): check every student one by one (no sorting needed)
int linearSearchRoll(vector<Student> &v, int roll) {
    for (int i = 0; i < (int)v.size(); i++) {
        comparisons++;
        if (v[i].roll == roll) return i;
    }
    return -1;
}

int linearSearchName(vector<Student> &v, string name) {
    for (int i = 0; i < (int)v.size(); i++) {
        comparisons++;
        if (lower(v[i].name) == lower(name)) return i;
    }
    return -1;
}

// Binary Search - O(log n): look at the middle and throw away half each time
// The list MUST be sorted by Roll No first.
int binarySearchRoll(vector<Student> &v, int roll) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if (v[mid].roll == roll)     return mid;
        else if (v[mid].roll < roll) low = mid + 1;   // look in right half
        else                         high = mid - 1;  // look in left half
    }
    return -1;
}
