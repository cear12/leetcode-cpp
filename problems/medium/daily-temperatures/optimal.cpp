class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
