#include <string>
#include <stack>
using namespace std;

// Эффективное решение: один проход со стеком
string decodeString(string s) {
    stack<int> counts;
    stack<string> results;
    string current;
    int k = 0;
    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            results.push(current);
            current.clear();
            k = 0;
        } else if (c == ']') {
            string temp = results.top();
            results.pop();
            int count = counts.top();
            counts.pop();
            while (count--) temp += current;
            current = temp;
        } else {
            current += c;
        }
    }
    return current;
}
// Временная сложность: O(n*m) — n символов, m максимальное повторение
// Пространственная сложность: O(n + m)
