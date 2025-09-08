class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();

        int times = ceil((double)m / n); // minimum repetitions needed
        string repeated = "";

        for (int i = 0; i < times; i++)
            repeated += a;
        if (repeated.find(b) != string::npos)
            return times;

        repeated += a; // one more repetition
        if (repeated.find(b) != string::npos)
            return times + 1;

        return -1;
    }

}
;