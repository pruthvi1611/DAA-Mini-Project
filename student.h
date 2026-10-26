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

long long comparisons = 0;


inline string lower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}