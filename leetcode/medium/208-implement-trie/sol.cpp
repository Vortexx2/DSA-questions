/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 208 - Implement Trie
 * @date 10-01-2023
 */
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
 public:
  bool terminal;
  vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);

  TrieNode() { terminal = false; }
};

int charToInt(char c) { return ((int)c - (int)'a'); }

class Trie {
 public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    int i = 0, n = word.size();
    TrieNode *curr = root, *next;

    while (i < n) {
      next = curr->children[charToInt(word[i])];
      if (next)
        curr = next;

      else {
        printf("char i (%d): %c\n", i, word[i]);
        next = new TrieNode();
        curr->children[charToInt(word[i])] = next;
        curr = next;
      }

      i++;
    }

    next->terminal = true;
  }

  bool search(string word) {
    int n = word.size();
    TrieNode *curr = root;

    for (auto &c : word) {
      if (!curr) return false;

      curr = curr->children[charToInt(c)];
    }

    return curr && curr->terminal;
  }

  bool startsWith(string prefix) {
    int n = prefix.size();
    TrieNode *curr = root;

    for (auto &c : prefix) {
      if (!curr) return false;

      curr = curr->children[charToInt(c)];
    }

    return curr;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */