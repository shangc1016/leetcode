#include "string.h"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

string TrimFront(string str) {
  if (str.empty()) return str;
  while (str[0] == ' ') str = str.substr(1);
  return str;
}

int myAtoi(string s) {
  // step1
  s = TrimFront(s);
  cout << "after trim:" << s << endl;
  int signal = 0;
  if (s[0] == '-') {
    signal = 1;
    s = s.substr(1);
  } else if (s[0] == '+') {
    s = s.substr(1);
  }
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if (!('0' <= s[i] && s[i] <= '9')) {
      index = i;
      break;
    }
  }
  if (index != 0) {
    s = s.substr(0, index);
  }

  int64_t value = 0;
  int64_t int32min = INT32_MIN;
  int64_t int32max = INT32_MAX;
  while (!s.empty()) {
    value = value * 10 + (s[0] - '0');
    s = s.substr(1);
    if (signal == 1 && value >= -int32min) return INT32_MIN;
    if (signal == 0 && value >= int32max) return INT32_MAX;
  }
  if (signal == 1) return -value;
  return value;
}

// 先把元素全部放到哈希表中，对哈希表中的每个元素x，判断x+1，x+2，x+3...是否存在，并且更新最长连续数组
// 优化：如果判断x+y是否存在，
int longestConsecutive(vector<int>& nums) {
  set<int> set;
  for (auto item : nums) {
    set.insert(item);
  }
  int logestIndex = 0;
  for (auto item : set) {
    if (set.count(item - 1)) {
      // 如果value-1存在，说明包含value-1的连续数组长度肯定大于当前value为起始的数组，直接跳过
      continue;
    }
    int tmp = item;
    int count = 0;
    while (set.count(tmp + 1)) {
      count++;
    }
    logestIndex = max(logestIndex, count);
    cout << "1" << endl;
  }
  return logestIndex;
}

vector<int> findAnagrams(string s, string p) {
  // 用map记录s、p的字符集合
  // 使用滑动窗口
  vector<int> result;

  if (p.size() > s.size()) return result;

  vector<int> sset(26, 0);
  vector<int> pset(26, 0);
  for (int i = 0; i < p.size(); i++) {
    sset[s[i] - 'a']++;
    pset[p[i] - 'a']++;
  }

  if (pset == sset) {
    // 如果两个集合元素相同
    result.push_back(0);
  }

  for (int i = 1; i < s.size() - p.size(); i++) {
    sset[s[i - 1] - 'a']--;
    sset[s[i + p.size()] - 'a']++;
    if (sset == pset) {
      result.push_back(i);
    }
  }
  return result;
}
class Solution_2409 {
 private:
  int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  struct Date {
    int month_;
    int day_;
  };

  void parser(string& str, Date& date) {
    int pos = str.find('-');
    date.month_ = stoi(str.substr(0, pos));
    date.day_ = stoi(str.substr(pos));
  }

  Date later(Date A, Date B) {
    if (A.month_ < B.month_)
      return B;
    else if (A.month_ > B.month_)
      return A;
    else {
      return A.day_ > B.day_ ? A : B;
    }
  }
  Date eailer(Date A, Date B) {
    if (A.month_ < B.month_)
      return A;
    else if (A.month_ > B.month_)
      return B;
    else {
      return A.day_ < B.day_ ? A : B;
    }
  }

 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    Date arriveAliceDate;
    Date leaveAliceDate;
    Date arriveBobDate;
    Date leaveBobDate;
    parser(arriveAlice, arriveAliceDate);
    parser(leaveAlice, leaveAliceDate);
    parser(arriveBob, arriveBobDate);
    parser(leaveBob, leaveBobDate);

    Date arrive = later(arriveAliceDate, arriveBobDate);
    Date leave = eailer(leaveAliceDate, leaveBobDate);

    cout << arrive.month_ << ", " << arrive.day_ << endl;
    cout << leave.month_ << ", " << leave.day_ << endl;

    int days = 0;
    for (int month = arrive.month_; month <= leave.month_; month++) {
      if (month == arrive.month_ && month == leave.month_) {
        days += leave.day_ - arrive.day_;
      } else if (month == arrive.month_) {
        days += dayOfMonth[arrive.month_] - arrive.day_;
      } else if (month == leave.month_) {
        days += leave.day_;
      } else {
        days += dayOfMonth[month];
      }
    }

    return days;
  }
};

// 和为K的连续子数组个数
int subarraySum(vector<int>& nums, int k) {
  int partSum = 0;
  int count = 0;
  int last = 0;
  for (int i = 0; i < nums.size(); i++) {
    while (partSum > k) {
      partSum -= nums[last++];
    }
    partSum += nums[i];

    if (partSum == k) {
      count++;
    }
  }

  return count;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  list<int> helper;
  vector<int> result;

  for (int i = 0; i < k; i++) {
    while (!helper.empty() && helper.back() <= nums[i]) helper.pop_back();
    helper.push_back(nums[i]);
  }

  result.push_back(helper.front());

  for (int i = k; i < nums.size(); i++) {
    if (helper.front() == nums[i - k]) helper.pop_front();
    while (!helper.empty() && helper.back() <= nums[i]) helper.pop_back();
    helper.push_back(nums[i]);
    result.push_back(helper.front());
  }
  return result;
}

}  // namespace mystring