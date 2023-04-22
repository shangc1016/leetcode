//
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  unordered_set<string> uset;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    uset.insert(tmp);
  }
  cout << uset.size() << endl;
  //
  return 0;
}