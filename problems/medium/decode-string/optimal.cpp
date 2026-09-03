#include "../../common/leetcode_common.h"

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

int main() {
    struct Case { string input; string expected; };
    vector<Case> cases = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
    };

    bool allOk = true;
    for (const auto& c : cases) {
        string result = decodeString(c.input);
        cout << "Input: s = \"" << c.input << "\"\n";
        cout << "Output: \"" << result << "\" -- expected \"" << c.expected << "\"\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
