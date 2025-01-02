class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n);
        unordered_set<char> u = {'a', 'e', 'i', 'o', 'u'};

        int s = 0;
        for (int i = 0; i < n; i++) {
            if (u.find(words[i][0]) != u.end() && u.find(words[i][words[i].length() - 1]) != u.end()) {
                pre[i] = s + 1;
                s = pre[i];
            } else {
                pre[i] = s;
            }
        }

        int m = queries.size();
        vector<int> ans(m);

        for (int j = 0; j < m; j++) {
            if (queries[j][0] == 0) {
                ans[j] = pre[queries[j][1]];
            } else {
                ans[j] = pre[queries[j][1]] - pre[queries[j][0] - 1];
            }
        }

        return ans;
    }
};
