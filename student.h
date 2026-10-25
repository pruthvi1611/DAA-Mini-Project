// student.h - the Student record and a counter for the analysis
#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

struct Student {
    int    roll;
    string name;
    string branch;
    float  cgpa;
};

// Counts how many comparisons an algorithm makes (used for analysis)
long long comparisons = 0;

// Makes text lowercase so "Neha" and "neha" are treated the same
inline string lower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}