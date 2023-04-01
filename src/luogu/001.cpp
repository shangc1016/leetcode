#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <vector>
using namespace std;

int main() {
  //
  //
  map<int, bool> status_;

  status_[1] = false;
  status_[2] = true;
  status_[100] = false;

  for (auto it = status_.begin(); it != status_.end(); it++) {
    cout << it->first << endl;
  }
  status_.erase(100);

  cout << "---" << endl;
  for (auto it = status_.begin(); it != status_.end(); it++) {
    cout << it->first << endl;
  }

  //
  return 0;
}