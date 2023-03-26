#ifndef __SORT_H_
#define __SORT_H_

#include <iostream>
#include <vector>
using namespace std;

namespace sort {

int findKthLargest(vector<int>& nums, int k);

int findKthLargest(vector<int>& nums, int k);
// 升序排序
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

}  // namespace sort

#endif