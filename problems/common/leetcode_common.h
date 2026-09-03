#pragma once

// Shared prelude for every solution file under problems/medium/. LeetCode's
// own judge pre-includes the standard library and pre-declares `using
// namespace std;` around every submission, so solutions are conventionally
// written assuming that environment rather than repeating a dozen
// #includes in every single file. This header reproduces that environment
// for local compilation, plus a handful of small print/build helpers
// shared by these files' demo main()s, and a single canonical ListNode
// definition (four of these problems operate on singly linked lists; they
// used to each define their own copy of this struct -- or, in one case,
// use it without defining it at all).
//
// `using namespace std` at header scope is ordinarily poor practice; it is
// deliberately scoped to this one directory of small, independent,
// LeetCode-style example programs, each compiled as its own translation
// unit, where it matches both the problems' original authored style and
// how virtually every published LeetCode solution looks.
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline ListNode* buildList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

inline vector<int> listToVector(ListNode* head) {
    vector<int> out;
    for (ListNode* n = head; n != nullptr; n = n->next) out.push_back(n->val);
    return out;
}

template <typename T>
void printVector(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

template <typename T>
void printVector2D(const vector<vector<T>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        printVector(v[i]);
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

inline void printBool(bool b) { cout << (b ? "true" : "false"); }
