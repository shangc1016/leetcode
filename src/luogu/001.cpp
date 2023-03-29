#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int size;
char first[11][11];
char result[11][11];
char second[11][11];

bool same(char A[][11], char B[][11]) {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      if (A[i][j] != B[i][j]) return false;
    }
  }
  return true;
}

// 顺时针旋转90
void op1() {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      result[i][j] = first[size - j + 1][i];
    }
  }
}

// 顺时针旋转180
void op2() {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      result[i][j] = first[size - i + 1][size - j + 1];
    }
  }
}

// 顺时针旋转270
void op3() {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      result[i][j] = first[j][size - i + 1];
    }
  }
}

// 反射，水平翻转
void op4() {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      result[i][j] = first[i][size - j + 1];
    }
  }
}

int main() {
  //
  //

  cin >> size;

  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      cin >> first[i][j];
    }
  }

  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      cin >> second[i][j];
    }
  }

  op1();
  if (same(result, second)) {
    cout << 1 << endl;
    return 0;
  }

  op2();
  if (same(result, second)) {
    cout << 2 << endl;
    return 0;
  }

  op3();
  if (same(result, second)) {
    return 0;
  }

  op4();
  if (same(result, second)) {
    cout << 4 << endl;
    return 0;
  }

  op1();
  if (same(result, second)) {
    cout << 5 << endl;
    return 0;
  }

  op2();
  if (same(result, second)) {
    cout << 5 << endl;
    return 0;
  }
  op3();
  if (same(result, second)) {
    cout << 5 << endl;
    return 0;
  }
  cout << 6 << endl;

  //
  return 0;
}