#include "sort.h"

#include <utility>
#include <vector>

namespace sort {

int partition(vector<int>& nums, int low, int high) {
  int i = low;
  int j = high + 1;
  int value = nums[low];
  while (true) {
    while (nums[++i] < value) {
      if (i >= high) break;
    }
    while (nums[--j] > value) {
      if (j <= low) break;
    }
    if (i >= j) break;
    swap(nums[i], nums[j]);
  }
  swap(nums[low], nums[j]);
  return j;
}

int findKthLargest(vector<int>& nums, int k) {
  int size = nums.size();
  int left = 0;
  int right = size - 1;
  

  while (true) {
    int pivot = partition(nums, left, right);
    if (pivot == size - k)
      return nums[pivot];
    else if (pivot > size - k) {
      //   在左边部分搜索
      right = pivot - 1;
      k -= size - pivot;
      size = size - pivot;
    } else {
      left = pivot + 1;
      size = size - pivot - 1;
    }
  }
}
}  // namespace sort