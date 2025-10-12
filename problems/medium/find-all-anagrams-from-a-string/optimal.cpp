class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
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
            int idxR = s[r] - 'a';
            if (freq[idxR] > 0) {
                // этот символ нужен — закрываем одну потребность
                --need;
            }
            --freq[idxR];

            // держим окно размера m
            if (r - l + 1 > m) {
                int idxL = s[l] - 'a';
                if (freq[idxL] >= 0) {
                    // возвращаем потребность по уходящему символу
                    ++need;
                }
                ++freq[idxL];
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
