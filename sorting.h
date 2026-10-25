// sorting.h - 5 sorting algorithms
// key: 1 = Roll No, 2 = Name, 3 = CGPA (highest first)
#pragma once
#include "student.h"

// true if a should come before b
bool before(Student a, Student b, int key) {
    comparisons++;
    if (key == 1) return a.roll < b.roll;
    if (key == 2) return lower(a.name) < lower(b.name);
    return a.cgpa > b.cgpa;
}

// 1. Bubble Sort - O(n^2): swap neighbours that are in the wrong order
void bubbleSort(vector<Student> &v, int key) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (before(v[j + 1], v[j], key))
                swap(v[j], v[j + 1]);
}

// 2. Selection Sort - O(n^2): pick the best element and put it in front
void selectionSort(vector<Student> &v, int key) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int best = i;
        for (int j = i + 1; j < n; j++)
            if (before(v[j], v[best], key))
                best = j;
        swap(v[i], v[best]);
    }
}

// 3. Insertion Sort - O(n^2): insert each record into the sorted part
void insertionSort(vector<Student> &v, int key) {
    for (int i = 1; i < (int)v.size(); i++) {
        Student current = v[i];
        int j = i - 1;
        while (j >= 0 && before(current, v[j], key)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current;
    }
}

// 4. Merge Sort - O(n log n): split in half, sort both halves, merge them
void mergeSort(vector<Student> &v, int left, int right, int key) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(v, left, mid, key);
    mergeSort(v, mid + 1, right, key);

    vector<Student> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (before(v[j], v[i], key)) temp.push_back(v[j++]);
        else                         temp.push_back(v[i++]);
    }
    while (i <= mid)   temp.push_back(v[i++]);
    while (j <= right) temp.push_back(v[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        v[left + k] = temp[k];
}

// 5. Quick Sort - O(n log n) average: pick a pivot, smaller ones go before it
void quickSort(vector<Student> &v, int low, int high, int key) {
    if (low >= high) return;
    Student pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (before(v[j], pivot, key)) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    quickSort(v, low, i, key);
    quickSort(v, i + 2, high, key);
}
