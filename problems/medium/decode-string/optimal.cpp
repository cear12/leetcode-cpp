#include "../../common/leetcode_common.h"

// Эффективное решение: один проход со стеком
string DecodeString(string s) {
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

int main() {
    struct Case { string input_; string expected_; };
    vector<Case> cases = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
    };

    bool all_ok = true;
    for (const auto& c : cases) {
        string result = DecodeString(c.input_);
        cout << "Input: s = \"" << c.input_ << "\"\n";
        cout << "Output: \"" << result << "\" -- expected \"" << c.expected_ << "\"\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
