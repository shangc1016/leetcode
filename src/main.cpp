#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


struct test {
  int val_;
  int arr_[];
};

int main() { cout << sizeof(test) << endl; }