class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char curr = s[right];

            if (lastIndex.find(curr) != lastIndex.end() && lastIndex[curr] >= left) {
                left = lastIndex[curr] + 1;
            }

            lastIndex[curr] = right;

            int len = right - left + 1;
            ans = max(ans, len);
        }

        return ans;
    }
};