class Solution {
public:
    // Function to count how many words in the 'words' vector are prefixes of the string 's'
    int countPrefixes(vector<string>& words, string s) {
        int count = 0; // Initialize the count of prefix matches
        
        // Loop through each word in the 'words' vector
        for (int i = 0; i < words.size(); i++) {
            // Extract the prefix of 's' with the same length as the current word
            string temp = s.substr(0, words[i].length());

            // If the prefix matches the current word, increment the count
            if (temp == words[i]) {
                count++;
            }
        }
        
        // Return the total count of prefixes found
        return count;
    }
};