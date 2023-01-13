/**
 * @file trie.cpp
 * @author Vortexx2
 * @brief Problem 14 - Longest Common Prefix
 * @date 13-01-2023
 * 
 * Runtime - 6 ms O(m * n)
 * Memory Usage - 9.7 MB O(m * n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
  struct TrieNode {
    bool last = false;
    unordered_map<char, TrieNode *> letters;
  };
  class Trie {
    TrieNode head;

   public:
    void addWord(const string &s) {
      TrieNode *p = &head;
      for (char c : s) {
        if (p->letters.count(c) == 0) {
          p->letters[c] = new TrieNode{};
        }
        p = p->letters[c];
      }
      p->last = true;
    }
    string lcp() {
      string ret;
      auto *p = &head;

      while (p->letters.size() == 1 && !p->last) {
        auto it = p->letters.begin();
        p = p->letters[it->first];
        ret += it->first;
      }
      return ret;
    }
  };

 public:
  string longestCommonPrefix(vector<string> &strs) {
    Trie trie;
    for (const auto &w : strs) {
      trie.addWord(w);
    }
    return trie.lcp();
  }
};