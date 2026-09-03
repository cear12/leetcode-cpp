#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> partitionLabels(const std::string& s) {
        std::unordered_map<char, int> last;
        for (int i = 0; i < s.size(); ++i)
            last[s[i]] = i;
        std::vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, last[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(k) где 
k
k — количество уникальных символов
