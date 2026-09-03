#include "../../common/leetcode_common.h"

class Solution {
public:
    vector<vector<int>> Merge(vector<vector<int>>& intervals) {
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
    struct Case { vector<vector<int>> intervals_; vector<vector<int>> expected_; };
    vector<Case> cases = {
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        {{{1, 4}, {4, 5}}, {{1, 5}}},
        {{{4, 7}, {1, 4}}, {{1, 7}}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        auto result = sol.Merge(c.intervals_);
        cout << "Input: intervals = ";
        PrintVector2D(c.intervals_);
        cout << "\nOutput: ";
        PrintVector2D(result);
        cout << " -- expected ";
        PrintVector2D(c.expected_);
        cout << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
