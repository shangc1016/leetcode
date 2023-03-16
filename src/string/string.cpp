#include "string.h"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

namespace mystring {

void reverseString(vector<char>& s) {
  //   双指针
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    swap(s[left++], s[right--]);
  }
}

string reverseStr(string s, int k) {
  for (int i = 0; i < s.size(); i += 2 * k) {
    if (i + k < s.size())
      reverse(s.begin() + i, s.begin() + i + k);
    else
      reverse(s.begin() + i, s.end());
  }
  return s;
}

string replaceSpace(string s) {
  string str;
  for (auto item : s) {
    if (item != ' ')
      str += item;
    else
      str += "%20";
  }
  return str;
}

// string reverseWords(string s) {
//   //   空格分割，
//   //   the sky is blue ->  blue is sky the
//   stack<string> stack;
//   int slow = 0;
//   int fast = 0;
//   while (fast < s.size()) {
//     while (fast < s.size() && s[fast] != ' ' && s[fast + 1] != ' ') fast++;
//   }
// }

// 左旋字符串
string reverseLeftWords(string s, int n) {
  n = n % s.size();
  string str;
  for (int i = n; i < s.size(); i++) str += s[i];
  for (int i = 0; i < n; i++) str += s[i];
  return str;
}

bool isInteger(string str) {
  if (str.empty()) return false;
  str = ElimateSignal(str);
  if (str.empty()) return false;
  for (int i = 0; i < str.size(); i++) {
    if (!('0' <= str[i] && str[i] <= '9')) return false;
  }
  return true;
}

bool isNoSignalInteger(string str) {
  if (str.empty()) return false;
  for (int i = 0; i < str.size(); i++) {
    if (!('0' <= str[i] && str[i] <= '9')) return false;
  }
  return true;
}

bool isDecimal(string str) {
  if (str.empty()) return false;
  str = ElimateSignal(str);

  int posDot = str.find('.');

  if (posDot < 0) return isInteger(str);
  if (posDot == 0 && str.size() == 1) return false;
  cout << "have dot" << endl;
  if (posDot == 0) return isNoSignalInteger(str.substr(1));
  if (posDot == str.size() - 1) return isInteger(str.substr(0, str.size() - 1));

  string front = str.substr(0, posDot);
  string tail = str.substr(posDot + 1);
  return isInteger(front) && isNoSignalInteger(tail);
}

string ElimateSignal(string str) {
  if (str.empty()) return str;
  if (str[0] == '+' || str[0] == '-') str = str.substr(1);
  return str;
}

int containE(string str) {
  int flagE = str.find('E');
  int flage = str.find('e');
  if (flagE == -1 && flage == -1) return -1;
  if (flagE == -1) return flage;
  return flagE;
}

string Trim(string str) {
  if (str.empty()) return str;
  int left = 0;
  int right = str.size() - 1;
  while (left < str.size() && str[left] == ' ') left++;
  while (right >= 0 && str[right] == ' ') right--;
  if (left > str.size() || right < 0) return "";
  return str.substr(left, right - left + 1);
}

// 判断字符串是否表示数字
bool isNumber(string s) {
  s = Trim(s);
  if (s.empty()) return false;

  cout << "after trim, str=[" << s << "]" << endl;

  int posE = containE(s);
  if (posE == 0 || posE == s.size() - 1) return false;
  if (posE > 0) {
    cout << "have E" << endl;
    string front = s.substr(0, posE);
    string tail = s.substr(posE + 1);
    return isDecimal(front) && isInteger(tail);
  } else {
    return isDecimal(s);
  }
  return false;
}

string trimFront(string str) {
  if (str.empty()) return str;
  int left = 0;
  while (str[left] == ' ') left++;
  return str.substr(left);
}

string TrimBack(string str) {
  if (str.empty()) return str;
  int left = 0;
  while (str[left] == '+' || str[left] == '-' ||
         ('0' <= str[left] && str[left] <= '9'))
    left++;
  return str.substr(0, left);
}

int strToInt(string str) {
  // 1 丢掉开头的空格
  str = trimFront(str);

  if (str.empty()) return 0;
  if (str[0] != '+' && str[0] != '-' && !('0' <= str[0] && str[0] <= '9'))
    return 0;
  str = TrimBack(str);
  if (str.empty()) return 0;

  int signal = 0;
  if (str[0] == '+') str = str.substr(1);
  if (str[1] == '-') {
    str = str.substr(1);
    signal = 1;
  }
  int64_t value = 0;
  for (int i = 0; i < str.size(); i++) {
    if (!('0' <= str[i] && str[i] <= '9')) return 0;
    value = value * 10 + (i - '0');
  }

  if (signal) value = -value;

  if (INT32_MIN <= value && value <= INT32_MAX)
    return value;
  else if (value < INT32_MIN)
    return INT32_MIN;
  else
    return INT32_MAX;
}

}  // namespace mystring