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
