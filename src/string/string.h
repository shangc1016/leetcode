#include <cstdint>
#include <cstring>
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

class Solution {
 private:
  string TrimFront(string str) {
    if (str.empty()) return str;
    int cur = 0;
    while (str[cur] == ' ') cur++;
    if (cur >= str.size()) return "";
    return str.substr(cur);
  }

  string DiscardTail(string str) {
    if (str.empty()) return str;
    int cur = 0;
    while (str[cur] == '+' || str[cur] == '-' ||
           ('0' <= str[cur] && str[cur] <= '9'))
      cur++;
    if (cur >= str.size()) return str;
    return str.substr(0, cur);
  }

  uint64_t Convert(string str, int signal) {
    uint64_t value = 0;
    for (int i = 0; i < str.size(); i++) {
      if (!('0' <= str[i] && str[i] <= '9')) return -1;
      if (signal == 0) {
        if (value >= INT32_MAX) return INT32_MAX;
        value = value * 10 + (str[i] - '0');
      } else if (signal == 1) {
        if (value <= INT32_MIN) return INT32_MIN;
        value = value * 10 - (str[i] - '0');
      }
    }
    return value;
  }

 public:
  int strToInt(string str) {
    str = TrimFront(str);
    if (str.empty()) return 0;
    str = DiscardTail(str);
    if (str.empty()) return 0;

    int signal = 0;
    if (str[0] == '-') {
      signal = 1;
      str = str.substr(1);
    } else if (str[0] == '+') {
      str = str.substr(1);
    }

    uint64_t value = Convert(str, signal);

    return value;
  }
};

}  // namespace mystring