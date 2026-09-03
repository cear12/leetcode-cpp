#include "../../common/leetcode_common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());  // Сортировка по start
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);            // Первый интервал всегда добавляем

        for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
            // Если текущий интервал пересекается с последним в merged
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]); // объединяем
            } else {
                merged.push_back(intervals[i]); // без пересечения — добавляем новый
            }
        }
        return merged;
    }
};
// Временная сложность: O(n log n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<vector<int>> intervals; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        {{{1, 4}, {4, 5}}, {{1, 5}}},
        {{{4, 7}, {1, 4}}, {{1, 7}}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        auto result = sol.merge(c.intervals);
        cout << "Input: intervals = ";
        printVector2D(c.intervals);
        cout << "\nOutput: ";
        printVector2D(result);
        cout << " -- expected ";
        printVector2D(c.expected);
        cout << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
