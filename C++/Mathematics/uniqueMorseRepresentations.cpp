// https://leetcode.com/problems/unique-morse-code-words/description/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      // step 1 : convert word into morse code
      // step 2 : add to set and return size of set

      vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
             "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; 
      unordered_set<string> ans;

      for (auto w : words) {
        string code;
        for (auto letter : w) {
          // step 1
          code += d[letter - 'a']; // convert word into morse
        }
        // step 2
        ans.insert(code); // add in set
      }
      return ans.size();
    }
};
