class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        string ans = "";
        char prev = '#';

        for (int k = 0; k < s.size(); k++) {

            char best = 0;
            int bestCnt = -1;

            for (auto& p : freq) {
                if (p.second > 0 && p.first != prev) {
                    if (p.second > bestCnt) {
                        best = p.first;
                        bestCnt = p.second;
                    }
                }
            }

            if (bestCnt == -1)
                return ""; // impossible

            ans.push_back(best);
            freq[best]--;
            prev = best;
        }
        return ans;
    }
};