class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";

        int bestStart = 0;
        int bestLen = 1;

        for (int i = 0; i < s.size(); i++) {
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);

            int maxLen = max(len1, len2);

            if (maxLen > bestLen) {
                bestLen = maxLen;
                bestStart = i - (maxLen - 1) / 2;
            }
        }

        return s.substr(bestStart, bestLen);
    }

private:
    int expandFromCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};