#include "../../common/leetcode_common.h"

/*
Stack с поддержкой getMin() за O(1) времени.
- data_  хранит все элементы.
- mins_  хранит историю минимальных значений, включая повторы.
*/
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        data_.push(val);
        // Если стек минимумов пуст или новый элемент <= текущему минимуму,
        // добавляем его в mins_ (учитываем повторы).
        if (mins_.empty() || val <= mins_.top()) {
            mins_.push(val);
        }
    }
    
    void pop() {
        if (data_.empty()) return;
        int topVal = data_.top();
        data_.pop();
        // Если удаляемый элемент равен текущему минимуму, 
        // извлекаем его из mins_.
        if (!mins_.empty() && topVal == mins_.top()) {
            mins_.pop();
        }
    }
    
    int top() {
        return data_.empty() ? -1 : data_.top();
    }
    
    int getMin() {
        return mins_.empty() ? -1 : mins_.top();
    }

private:
    stack<int> data_;
    stack<int> mins_;
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
