#include "../../common/leetcode_common.h"

/*
Стек пар {value, currentMin}:
- При каждом push храним вместе с value и минимум на этот момент.
- pop, top, getMin реализуются за O(1).
*/
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        int currentMin = st_.empty() ? val : min(val, st_.top().second);
        // Сохраняем пару: значение + минимум после вставки
        st_.push({val, currentMin});
    }
    
    void pop() {
        if (!st_.empty()) st_.pop();
    }
    
    int top() {
        return st_.empty() ? -1 : st_.top().first;
    }
    
    int getMin() {
        return st_.empty() ? -1 : st_.top().second;
    }

private:
    stack<pair<int,int>> st_;
};

int main() {
    cout << "Input: push(-2), push(0), push(-3), getMin(), pop(), top(), getMin()\n";

    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    int min1 = st.getMin(); // expected -3
    st.pop();
    int top1 = st.top();    // expected 0
    int min2 = st.getMin(); // expected -2

    cout << "Output: getMin()=" << min1 << ", top()=" << top1 << ", getMin()=" << min2
         << " -- expected -3, 0, -2\n";

    bool ok = min1 == -3 && top1 == 0 && min2 == -2;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
