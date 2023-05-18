/**
 * @file sliding-window.cpp
 * @author Vortexx2
 * @brief Problem 30 - Substring with Concatenation of All Words
 * @approach Using a sliding window approach
 * @date 18-05-2023
 * 
 * Runtime - 916 ms O(s.size() * words.size() * wordSize)
 * Memory Usage - 286.6 MB O(words.size() * wordSize)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    int numWords = words.size(),     // number of words
        wordSize = words[0].size();  // size of each word (which is constant)

    if (s.size() < numWords * wordSize) return {};

    unordered_map<string, int> wordDic;
    for (int i = 0; i < numWords; i++) {
      if (!wordDic[words[i]]) wordDic.insert({words[i], 0});

      wordDic[words[i]]++;
    }

    vector<int> res;

    int l = 0;
    while (l <= s.size() - (numWords * wordSize)) {
      unordered_map<string, int> copyDic = wordDic;

      string curr = s.substr(l, wordSize);
      int temp = l;
      while (copyDic.find(curr) != copyDic.end()) {
        copyDic[curr]--;

        if (copyDic[curr] == 0) copyDic.erase(curr);

        temp += wordSize;

        curr = s.substr(temp, wordSize);
      }

      if (copyDic.empty()) res.push_back(l);

      l++;
    }

    return res;
  }
};

int main() {
  Solution sol = Solution();
  string s = "wordgoodgoodgoodbestword";
  vector<string> wordDic = {"word", "good", "best", "good"};

  vector<int> res = sol.findSubstring(s, wordDic);
  cout << "{ ";

  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";

  cout << "}" << endl;
}