#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) { return (int)(c - 'a'); }

int intToChar(int c) { return (char)(c + 'a'); }

class TrieNode {
 public:
  char value;
  bool terminal;
  vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);

  TrieNode(char val) {
    value = val;
    terminal = false;
  }
};

class Trie {
 public:
  TrieNode *root;

  Trie() { root = new TrieNode('$'); }

  void insert(string word) {
    TrieNode *curr = root, *next;

    for (auto &c : word) {
      next = curr->children[charToInt(c)];

      if (!next) {
        next = new TrieNode(c);
        curr->children[charToInt(c)] = next;
      }

      curr = next;
    }

    curr->terminal = true;
  }

  bool search(string word) {
    TrieNode *curr = root;

    for (auto &c : word) {
      curr = curr->children[charToInt(c)];

      if (!curr) return false;
    }

    return curr->terminal;
  }

  bool searchPrefix(string prefix) {
    TrieNode *curr = root;

    for (auto &c : prefix) {
      curr = curr->children[charToInt(c)];

      if (!curr) return false;
    }

    return true;
  }

  void insertAll(vector<string> &words) {
    for (auto &word : words) {
      insert(word);
    }
  }
};

class Solution {
 public:
  string og;
  vector<string> res;
  string sentence;
  Trie *t;

  void helper(TrieNode *curr, int index, string &currWord) {
    if (index >= og.size()) return;

    TrieNode *next = curr->children[charToInt(og[index])];

    // if trie does not have current word
    if (!next) return;

    // current prefix exists in the trie
    // add current character to currWord
    currWord.push_back(og[index]);

    // currWord exists in our dictionary, we need to check if the rest of the
    // substring makes any sense
    if (next->terminal) {
      // perform normal backtracking
      string oldSentence = sentence;

      if (index == og.size() - 1) {
        sentence += currWord;
        res.push_back(sentence);
        sentence = oldSentence;
        return;
      }

      sentence += currWord + " ";

      string oldCurrWord = currWord;
      currWord = "";

      helper(t->root, index + 1, currWord);
      
      sentence = oldSentence;
      currWord = oldCurrWord;
    }

    helper(next, index + 1, currWord);

    currWord.pop_back();
  }

  vector<string> wordBreak(string s, vector<string> &wordDict) {
    t = new Trie();
    t->insertAll(wordDict);

    og = s;
    res = {};
    string currWord = "";
    sentence = "";

    helper(t->root, 0, currWord);

    return res;
  }
};