
## 字符串排列（有重复元素）

```cpp
class Solution {
 private:
  vector<string> result;
  string tmp;

  void backtracing(string &s, vector<bool> &used) {
    if (tmp.size() == s.size()) {
      result.push_back(tmp);
      return;
    }
    for (int i = 0; i < s.size(); i++) {
      if (used[i]) continue;
      if (i > 0 && s[i] == s[i - 1] && used[i - 1] == false) continue;
      tmp.push_back(s[i]);
      used[i] = true;
      backtracing(s, used);
      tmp.pop_back();
      used[i] = false;
    }
  }

 public:
  vector<string> permutation(string s) {
    vector<bool> used(s.size(), false);
    // 为什么要排序呢？
    // 因为在backtracing函数中美，是根据s[i]==s[i-1]进行判断去重的，
    // 如果不排序，s[i]==s[i-1]的情况不能保证后面再没有相同的元素了
    // 比如{1,2,3,1,2}，在第二个1的时候，检查s[i]==s[i-1]不能保证前面没有重复的元素1了
    sort(s.begin(), s.end());
    backtracing(s, used);
    return result;
  }
};
```