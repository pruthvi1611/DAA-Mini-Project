// main.cpp - Student Record Sorting & Searching System (DAA Mini Project)
// Compile: g++ -std=c++17 main.cpp -o student_system
#include <iostream>
#include <iomanip>
#include "student.h"
#include "sorting.h"
#include "searching.h"

// ---------- small input helpers ----------
int readInt(string msg) {
    int x;
    cout << msg;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a number: ";
    }
    cin.ignore(1000, '\n');
    return x;
}

float readFloat(string msg) {
    float x;
    cout << msg;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a number: ";
    }
    cin.ignore(1000, '\n');
    return x;
}

string readText(string msg) {
    string s;
    cout << msg;
    getline(cin, s);
    return s;
}

// ---------- display ----------
void showStudent(Student s) {
    cout << left << setw(8) << s.roll << setw(22) << s.name
         << setw(8) << s.branch << fixed << setprecision(2) << s.cgpa << "\n";
}

void showAll(vector<Student> &v) {
    cout << left << setw(8) << "Roll" << setw(22) << "Name"
         << setw(8) << "Branch" << "CGPA\n";
    cout << "----------------------------------------------\n";
    for (Student s : v) showStudent(s);
    cout << "Total students: " << v.size() << "\n";
}

// ---------- menu actions ----------
void addStudent(vector<Student> &v) {
    Student s;
    s.roll = readInt("Roll No: ");
    for (Student x : v)
        if (x.roll == s.roll) { cout << "Roll No already exists.\n"; return; }
    s.name   = readText("Name: ");
    s.branch = readText("Branch: ");
    s.cgpa   = readFloat("CGPA: ");
    v.push_back(s);
    cout << "Student added.\n";
}

void sortStudents(vector<Student> &v) {
    cout << "1. Bubble  2. Selection  3. Insertion  4. Merge  5. Quick\n";
    int algo = readInt("Choose algorithm: ");
    cout << "1. Roll No  2. Name  3. CGPA\n";
    int key = readInt("Sort by: ");
    if (algo < 1 || algo > 5 || key < 1 || key > 3) { cout << "Invalid choice.\n"; return; }

    comparisons = 0;
    if (algo == 1) bubbleSort(v, key);
    if (algo == 2) selectionSort(v, key);
    if (algo == 3) insertionSort(v, key);
    if (algo == 4) mergeSort(v, 0, v.size() - 1, key);
    if (algo == 5) quickSort(v, 0, v.size() - 1, key);

    cout << "Sorted! Comparisons made: " << comparisons << "\n";
}

void searchStudent(vector<Student> &v) {
    cout << "1. Linear search by Roll No\n"
         << "2. Binary search by Roll No (list must be sorted by Roll No)\n"
         << "3. Linear search by Name\n";
    int choice = readInt("Choose: ");

    comparisons = 0;
    int pos = -1;
    if (choice == 1) pos = linearSearchRoll(v, readInt("Roll No: "));
    else if (choice == 2) pos = binarySearchRoll(v, readInt("Roll No: "));
    else if (choice == 3) pos = linearSearchName(v, readText("Name: "));
    else { cout << "Invalid choice.\n"; return; }

    if (pos == -1) cout << "Student not found.\n";
    else { cout << "Found:\n"; showStudent(v[pos]); }
    cout << "Comparisons made: " << comparisons << "\n";
}

// ---------- main ----------
int main() {
    vector<Student> students = {
        {112, "Rahul Patel",   "IT",  8.45}, {105, "Neha Shah",     "IT",  9.10},
        {130, "Amit Desai",    "CSE", 7.80}, {101, "Priya Mehta",   "IT",  8.90},
        {118, "Karan Joshi",   "ECE", 6.95}, {125, "Sneha Trivedi", "IT",  9.35},
        {109, "Vivek Rana",    "CSE", 7.20}, {122, "Anjali Parmar", "IT",  8.10},
        {103, "Mehul Thakkar", "ECE", 6.50}, {115, "Pooja Solanki", "IT",  8.75}
    };

    int choice;
    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n"
             << "1. Show all students\n"
             << "2. Add a student\n"
             << "3. Sort students\n"
             << "4. Search a student\n"
             << "0. Exit\n";
        choice = readInt("Enter choice: ");
        cout << "\n";

        if (choice == 1) showAll(students);
        else if (choice == 2) addStudent(students);
        else if (choice == 3) sortStudents(students);
        else if (choice == 4) searchStudent(students);
        else if (choice != 0) cout << "Invalid choice.\n";
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
