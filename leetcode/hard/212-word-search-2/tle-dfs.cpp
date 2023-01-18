/**
 * @file tle-dfs.cpp
 * @author Vortexx2
 * @brief Problem 212 - Word Search 2
 * @date 18-01-2023
 * 
 * Runtime - TLE
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  set<string> wordDic;
  int maxWordLength;
  int m, n;

  set<string> wordsEncountered;

  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  vector<string> res;

  void fillWords(vector<string>& words) {
    for (auto& w : words) {
      wordDic.insert(w);
      maxWordLength = max(maxWordLength, (int)w.size());
    }
  }

  void dfs(int row, int col, vector<vector<char>>& board, vector<char>& path,
           set<pair<int, int>>& visited) {
    if (path.size() > maxWordLength) return;

    string word = string(path.begin(), path.end());
    // word exists
    if (wordDic.find(word) != wordDic.end()) wordsEncountered.insert(word);

    if (row < 0 || row >= m || col < 0 || col >= n) return;

    // if already existed in visited
    if (visited.find({row, col}) != visited.end()) return;

    path.push_back(board[row][col]);
    visited.insert({row, col});

    for (auto& d : dirs) {
      dfs(row + d.first, col + d.second, board, path, visited);
    }

    path.pop_back();
    visited.erase({row, col});
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // fills words to set for O(1) access
    fillWords(words);

    res = {};

    m = board.size(), n = board[0].size();
    set<pair<int, int>> visited;
    vector<char> path = {};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(i, j, board, path, visited);
      }
    }

    vector<string> res(wordsEncountered.begin(), wordsEncountered.end());
    return res;
  }
};