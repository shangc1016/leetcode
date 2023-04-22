#include <algorithm>
#include <cstdint>
#include <cstring>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace mystring {

void reverseString(vector<char>& s);

string reverseStr(string s, int k);

string replaceSpace(string s);

// TODO
string reverseWords(string s);

string reverseLeftWords(string s, int n);

bool isNumber(string s);

bool isInteger(string str);

bool isDecimal(string str);

string ElimateSignal(string str);

int containE(string str);

int strToInt(string str);

int myAtoi(string s);

// class Solution {
//  private:
//   string TrimFront(string str) {
//     if (str.empty()) return str;
//     int cur = 0;
//     while (str[cur] == ' ') cur++;
//     if (cur >= str.size()) return "";
//     return str.substr(cur);
//   }

//   string DiscardTail(string str) {
//     if (str.empty()) return str;
//     int cur = 0;
//     while (str[cur] == '+' || str[cur] == '-' ||
//            ('0' <= str[cur] && str[cur] <= '9'))
//       cur++;
//     if (cur >= str.size()) return str;
//     return str.substr(0, cur);
//   }

//   uint64_t Convert(string str, int signal) {
//     uint64_t value = 0;
//     for (int i = 0; i < str.size(); i++) {
//       if (!('0' <= str[i] && str[i] <= '9')) return -1;
//       if (signal == 0) {
//         if (value >= INT32_MAX) return INT32_MAX;
//         value = value * 10 + (str[i] - '0');
//       } else if (signal == 1) {
//         if (value <= INT32_MIN) return INT32_MIN;
//         value = value * 10 - (str[i] - '0');
//       }
//     }
//     return value;
//   }

//  public:
//   int strToInt(string str) {
//     str = TrimFront(str);
//     if (str.empty()) return 0;
//     str = DiscardTail(str);
//     if (str.empty()) return 0;

//     int signal = 0;
//     if (str[0] == '-') {
//       signal = 1;
//       str = str.substr(1);
//     } else if (str[0] == '+') {
//       str = str.substr(1);
//     }

//     uint64_t value = Convert(str, signal);

//     return value;
//   }
// };

class Solution {
 private:
  struct Node {
    char ch_;
    bool is_end_{false};
    Node* next_[26];
    Node(char ch) : ch_(ch) {
      for (int i = 0; i < 26; i++) next_[i] = nullptr;
    }
  };

  Node* root_{nullptr};

  void NewTrimTree() { root_ = new Node('\0'); }

  void InsertTrim(string str) {
    Node* ptr = root_;
    while (str.size() > 0) {
      if (ptr->next_[str[0] - '0'] == nullptr) {
        ptr->next_[str[0] - '0'] = new Node(str[0] - '0');
      }
      ptr = ptr->next_[str[0] - '0'];
      str = str.substr(1);
    }
    ptr->is_end_ = true;
  }

  void FindPrefix(string& prefix) {
    Node* ptr = root_;

    Node* next;
    while (true) {
      int count = 0;
      for (int i = 0; i < 25; i++) {
        if (ptr->next_[i] != nullptr) {
          count++;
          next = ptr->next_[i];
        }
      }
      if (count == 1) {
        ptr = next;
        prefix += (ptr->ch_ + 'a');
      } else {
        return;
      }
      if (ptr->is_end_) return;
    }
  }

 public:
  string longestCommonPrefix(vector<string>& strs) {
    NewTrimTree();
    for (auto str : strs) InsertTrim(str);
    string prefix;
    FindPrefix(prefix);
    return prefix;
  }
};

// 对每个字符串排序，如果是异位的字符串，它排序的结果是相同的，用map存储
class Solution_49 {
 private:
  string helper(const string& str) {
    string tmp = str;
    std::sort(tmp.begin(), tmp.end());
    return tmp;
  }

 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> map;
    for (auto str : strs) {
      map[helper(str)].push_back(str);
    }
    vector<vector<string>> vec;
    for (auto item : map) {
      vec.push_back(item.second);
    }
    return vec;
  }
};

int longestConsecutive(vector<int>& nums);

}  // namespace mystring