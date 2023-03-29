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

  printf("%0*d\n", 12, 6);

  //
  return 0;
}