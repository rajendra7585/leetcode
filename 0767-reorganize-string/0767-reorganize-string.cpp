class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> f;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            f[s[i]]++;
        }
        char prev = '#';
        string ans = "";
        for (int k = 0; k < n; k++) {
            char best = 0;
            int bc = -1;
            for (const auto j : f) {
                if (j.second > 0 && j.first != prev) {
                    if (j.second > bc) {
                        best = j.first;
                        bc = j.second;
                    }
                }
            }
            if (bc == -1)
                return "";

            ans.push_back(best);
            f[best]--;
            prev = best;
        }
        return ans;
    }
};