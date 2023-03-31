## 数组中的第K个最大元素
两只思路：
- 快排，根据pivot快速将数组分成可以确定大小的两部分
- 堆排序，排序开销小


### 快排

```cpp
class QuickSort {
 private:
  static int partition(vector<int>& nums, int low, int high) {
    int i = low;
    int j = high + 1;
    int value = nums[low];
    while (true) {
      while (nums[++i] < value)
        if (i == high) break;
      while (value < nums[--j])
        if (j == low) break;
      if (i >= j) break;
      std::swap(nums[i], nums[j]);
    }
    std::swap(nums[low], nums[j]);
    return j;
  }

  static void quick_sort(vector<int>& nums, int low, int high) {
    if (low >= high) return;
    // 寻找枢轴，然后以枢轴为界，分治
    int pivot = partition(nums, low, high);
    quick_sort(nums, low, pivot - 1);
    quick_sort(nums, pivot + 1, high);
  }

 public:
  static void quickSort(vector<int>& nums) {
    quick_sort(nums, 0, nums.size() - 1);
  }
};
```

快排有个问题，如果数组基本有序。那么复杂度近似为`O(n^2)`。
需要改进的点在于，随机选择相比较的元素


### pivot枢轴随机选择的快排
```cpp
template <class Key>
class ShuffleQuickSort {
 private:
  static int partition(vector<Key>& vec, int low, int high) {
    int i = low;
    int j = high + 1;
    int value = vec[low];
    while (true) {
      while (vec[++i] < value) {
        if (i == high) break;
      }
      while (value < vec[--j]) {
        if (j == low) break;
      }
      if (i >= j) break;
      std::swap(vec[i], vec[j]);
    }
    std::swap(vec[low], vec[j]);
    return j;
  }

  static int random_partition(vector<Key>& vec, int low, int high) {
    int rand = std::rand() % (high - low + 1) + low;
    std::swap(vec[rand], vec[high]);
    return partition(vec, low, high);
  }
  static void quick_sort(vector<Key>& vec, int low, int high) {
    if (low >= high) return;
    int pivot = random_partition(vec, low, high);
    quick_sort(vec, low, pivot - 1);
    quick_sort(vec, pivot + 1, high);
  }

 public:
  static void QuickSort(vector<Key>& vec) { quick_sort(vec, 0, vec.size() - 1); }
};
```

![20230327145534](https://note-img-1300721153.cos.ap-nanjing.myqcloud.com/md-img20230327145534.png)


### 计数排序


```cpp
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//快速读入
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
```