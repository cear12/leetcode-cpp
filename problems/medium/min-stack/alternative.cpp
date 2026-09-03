#include "../../common/leetcode_common.h"

/*
Стек пар {value, current_min}:
- При каждом Push храним вместе с value и минимум на этот момент.
- Pop, Top, GetMin реализуются за O(1).
*/
class MinStack {
 public:
  MinStack() {}

  void Push(int val) {
    int current_min = st_.empty() ? val : min(val, st_.top().second);
    // Сохраняем пару: значение + минимум после вставки
    st_.push({val, current_min});
  }

  void Pop() {
    if (!st_.empty()) st_.pop();
  }

  int Top() { return st_.empty() ? -1 : st_.top().first; }

  int GetMin() { return st_.empty() ? -1 : st_.top().second; }

 private:
  stack<pair<int, int>> st_;
};

int main() {
  cout << "Input: Push(-2), Push(0), Push(-3), GetMin(), Pop(), Top(), "
          "GetMin()\n";

  MinStack st;
  st.Push(-2);
  st.Push(0);
  st.Push(-3);
  int min1 = st.GetMin();  // expected -3
  st.Pop();
  int top1 = st.Top();     // expected 0
  int min2 = st.GetMin();  // expected -2

  cout << "Output: GetMin()=" << min1 << ", Top()=" << top1
       << ", GetMin()=" << min2 << " -- expected -3, 0, -2\n";

  bool ok = min1 == -3 && top1 == 0 && min2 == -2;
  cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  return ok ? 0 : 1;
}
