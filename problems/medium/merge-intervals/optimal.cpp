class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());  // Сортировка по start
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);            // Первый интервал всегда добавляем

        for (int i = 1; i < intervals.size(); ++i) {
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
