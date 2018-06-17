// Write a function that takes a string as input and returns the string reversed.
//
// Example:
// Given s = "hello", return "olleh".


class Solution {
public:
    string reverseString(string s) {
      int n = s.length();
      // Solution #1 : brute force : reverse traversal
      // O(n) in time and space
      // std::string rev_s;
      // for (int i=(n-1); i<=0; i--){
      //   rev_s.push_back(s[i]);
      // }
      // return rev_s;

      // Solution #2 : use std::reverse from #include<algorithm>
      // O(n/2) : algorithm internally is the same as the next solution.
      // O(1) : space complexity
      // std::reverse(s.begin(), s.end());
      // return s;

      // Solution #3 : interchange characters starting from out - moving inwards
      // O(n/2) : traverses half the string and swaps elements
      // O(1) : space complexity
      for (int i=0; i<(n/2); i++){
        s[i] ^= s[n-1-i];
        s[n-1-i] ^= s[i];
        s[i] ^= s[n-1-i];
      }
      return s;
    }
  }
