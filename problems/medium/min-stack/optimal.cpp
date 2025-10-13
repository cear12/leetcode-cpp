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
