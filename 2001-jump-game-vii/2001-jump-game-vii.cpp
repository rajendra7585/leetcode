class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int farthest = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) {
                return true;
            }

            for (int j = max(i + minJump, farthest + 1); j <= min(i + maxJump, n - 1); ++j) {
                if (s[j] == '0' && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }

            farthest = max(farthest, i + maxJump);
        }

        return false;
    }
};