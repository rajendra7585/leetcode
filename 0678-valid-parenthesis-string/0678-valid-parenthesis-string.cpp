class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, n = s.length();
        
        // First pass: from left to right
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*') left++;
            else left--;
            
            if (left < 0) return false;  // Too many ')' without matching '(' or '*'
        }
        
        // Second pass: from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') right++;
            else right--;
            
            if (right < 0) return false;  // Too many '(' without matching ')' or '*'
        }
        
        return true;  // If both passes are valid, the string is balanced
    }
};
