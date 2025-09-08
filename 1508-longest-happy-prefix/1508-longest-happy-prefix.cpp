class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int len = 0; // length of the previous longest prefix suffix
        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];

            if (s[i] == s[len])
                len++;

            lps[i] = len;
        }

        // The last value of lps array tells us the length of the longest happy
        // prefix
        return s.substr(0, lps[n - 1]);
    }
};