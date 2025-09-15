// Жадное решение — фиксируем последний индекс каждого символа
class Solution {
public:
    std::vector<int> partitionLabels(const std::string& s) {
        std::vector<int> res, last(26);
        for (int i = 0; i < s.size(); ++i)
            last[s[i] - 'a'] = i;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, last[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

// Временная сложность: O(n) — один проход по строке.
// Пространственная сложность: O(1) — 26 символов латинского алфавита
