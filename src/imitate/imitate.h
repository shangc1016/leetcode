#ifndef __IMITATE_H_
#define __IMITATE_H_

#include <list>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace imitate {

bool validateStackSequences(vector<int>& pushed, vector<int>& popped);

class Solution {
 public:
  bool validIndex(int index, int size) { return (0 <= index && index <= size); }
  bool canReach(vector<int>& arr, int start) {
    //
    //
    vector<bool> visited(arr.size(), false);
    vector<bool> reachable(arr.size(), false);

    int size = arr.size();

    queue<int> queue;
    queue.push(start);
    while (!queue.empty()) {
      auto index = queue.front();
      queue.pop();
      if (validIndex(index, size) && !visited[index]) {
        reachable[index] = true;
        visited[index] = true;
        if (arr[index] == 0) return true;
        if (validIndex(index + arr[index], size) &&
            !visited[index + arr[index]]) {
          queue.push(index + arr[index]);
        }
        if (validIndex(index - arr[index], size) &&
            !visited[index + arr[index]]) {
          queue.push(index - arr[index]);
        }
      }
    }
    return false;
  }
};

class Solution_118 {
 private:
  vector<int> WhichLevle(int level) {
    if (level == 0)
      return {1};
    else if (level == 1)
      return {1, 1};
    else {
      auto prev_level = WhichLevle(level - 1);
      vector<int> this_level;
      this_level.push_back(1);
      for (int i = 0; i < prev_level.size() - 1; i++) {
        this_level.push_back(prev_level[i + 1] + prev_level[i]);
      }
      this_level.push_back(1);
      return this_level;
    }
  }

 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++) {
      result.push_back(WhichLevle(i));
    }
    return result;
  }
};

// 位操作
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  while ((n & 1) == 0) n = n >> 1;
  if (n == -1 || n == 1) return true;
  return false;
}

int calPoints(vector<string>& operations) {
  vector<int> scores;
  for (auto op : operations) {
    if (op == "+") {
      int size = scores.size();
      int score = scores[size - 1] + scores[size - 2];
      scores.push_back(score);
      break;
    } else if (op == "C") {
      scores.pop_back();
      break;
    } else if (op == "D") {
      scores.push_back(scores.back() * 2);
    } else {
      scores.push_back(stoi(op));
    }
  }
  int sum = 0;
  for (auto item : scores) sum += item;
  return sum;
}

}  // namespace imitate

#endif