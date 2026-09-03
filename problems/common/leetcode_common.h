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
  int val_;
  ListNode* next_;
  ListNode() : val_(0), next_(nullptr) {}
  ListNode(int x) : val_(x), next_(nullptr) {}
  ListNode(int x, ListNode* next) : val_(x), next_(next) {}
};

inline ListNode* BuildList(const vector<int>& values) {
  ListNode dummy(0);
  ListNode* tail = &dummy;
  for (int v : values) {
    tail->next_ = new ListNode(v);
    tail = tail->next_;
  }
  return dummy.next_;
}

inline vector<int> ListToVector(ListNode* head) {
  vector<int> out;
  for (ListNode* n = head; n != nullptr; n = n->next_) out.push_back(n->val_);
  return out;
}

template <typename T>
void PrintVector(const vector<T>& v) {
  cout << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i + 1 < v.size()) cout << ", ";
  }
  cout << "]";
}

template <typename T>
void PrintVector2D(const vector<vector<T>>& v) {
  cout << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    PrintVector(v[i]);
    if (i + 1 < v.size()) cout << ", ";
  }
  cout << "]";
}

inline void PrintBool(bool b) { cout << (b ? "true" : "false"); }
