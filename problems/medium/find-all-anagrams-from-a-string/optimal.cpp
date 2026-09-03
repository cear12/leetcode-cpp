#include "../../common/leetcode_common.h"
#include <array>  // std::array used below; not guaranteed transitively by the common header

class Solution {
public:
    vector<int> FindAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (m > n) return ans;

        // freq[i] > 0 означает, что символа ('a'+i) не хватает в окне
        // freq[i] < 0 означает, что этого символа в окне больше, чем нужно
        array<int,26> freq{}; freq.fill(0);
        for (char c : p) freq[c - 'a']++;

        int need = m; // сколько символов ещё нужно "закрыть" для анаграммы
        int l = 0;
        for (int r = 0; r < n; ++r) {
            int idx_r = s[r] - 'a';
            if (freq[idx_r] > 0) {
                // этот символ нужен — закрываем одну потребность
                --need;
            }
            --freq[idx_r];

            // держим окно размера m
            if (r - l + 1 > m) {
                int idx_l = s[l] - 'a';
                if (freq[idx_l] >= 0) {
                    // возвращаем потребность по уходящему символу
                    ++need;
                }
                ++freq[idx_l];
                ++l;
            }

            if (r - l + 1 == m && need == 0) {
                ans.push_back(l);
            }
        }
        return ans;
    }
};
// Время: O(n)
// Память: O(1)

int main() {
    struct Case { string s_; string p_; vector<int> expected_; };
    vector<Case> cases = {
        {"cbaebabacd", "abc", {0, 6}},
        {"abab", "ab", {0, 1, 2}},
    };

    bool all_ok = true;
    Solution sol;
    for (const auto& c : cases) {
        vector<int> result = sol.FindAnagrams(c.s_, c.p_);
        cout << "Input: s = \"" << c.s_ << "\", p = \"" << c.p_ << "\"\n";
        cout << "Output: ";
        PrintVector(result);
        cout << " -- expected ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
