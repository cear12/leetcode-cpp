#include "../../common/leetcode_common.h"

/*
Stack с поддержкой GetMin() за O(1) времени.
- data_  хранит все элементы.
- mins_  хранит историю минимальных значений, включая повторы.
*/
class MinStack {
public:
    MinStack() {}
    
    void Push(int val) {
        data_.push(val);
        // Если стек минимумов пуст или новый элемент <= текущему минимуму,
        // добавляем его в mins_ (учитываем повторы).
        if (mins_.empty() || val <= mins_.top()) {
            mins_.push(val);
        }
    }
    
    void Pop() {
        if (data_.empty()) return;
        int top_val = data_.top();
        data_.pop();
        // Если удаляемый элемент равен текущему минимуму, 
        // извлекаем его из mins_.
        if (!mins_.empty() && top_val == mins_.top()) {
            mins_.pop();
        }
    }
    
    int Top() {
        return data_.empty() ? -1 : data_.top();
    }
    
    int GetMin() {
        return mins_.empty() ? -1 : mins_.top();
    }

private:
    stack<int> data_;
    stack<int> mins_;
};

int main() {
    cout << "Input: Push(-2), Push(0), Push(-3), GetMin(), Pop(), Top(), GetMin()\n";

    MinStack st;
    st.Push(-2);
    st.Push(0);
    st.Push(-3);
    int min1 = st.GetMin(); // expected -3
    st.Pop();
    int top1 = st.Top();    // expected 0
    int min2 = st.GetMin(); // expected -2

    cout << "Output: GetMin()=" << min1 << ", Top()=" << top1 << ", GetMin()=" << min2
         << " -- expected -3, 0, -2\n";

    bool ok = min1 == -3 && top1 == 0 && min2 == -2;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
