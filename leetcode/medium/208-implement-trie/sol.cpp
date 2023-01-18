/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 208 - Implement Trie
 * @date 10-01-2023
 */
#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) { return (int)(c - 'a'); }

class TrieNode {
 public:
  bool terminal;
  vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);

  TrieNode() { terminal = false; }
};

class Trie {
 private:
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *curr = root, *nextNode;

    for (auto& c : word) {
      nextNode = curr->children[charToInt(c)];

      if (!nextNode) curr->children[charToInt(c)] = new TrieNode();

      curr = curr->children[charToInt(c)];
    }

    curr->terminal = true;
  }

  bool search(string word) {
    TrieNode* currNode = root;

    for (auto& c : word) {
      if (!currNode) return false;

      currNode = currNode->children[charToInt(c)];
    }

    return (currNode && currNode->terminal);
  }

  bool startsWith(string prefix) {
    TrieNode* curr = root;

    for (auto& c : prefix) {
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