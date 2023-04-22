// https://www.luogu.com.cn/problem/P1046

#include <iostream>

using namespace std;
const int stir = 30;
int arr[10];
int main() {
  //

  int height{};
  int count{};

  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }
  cin >> height;
  for (int i = 0; i < 10; i++) {
    if (height + stir >= arr[i]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}