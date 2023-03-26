## 数组中的第K个最大元素
两只思路：
- 快排，根据pivot快速将数组分成可以确定大小的两部分
- 堆排序，排序开销小


#### 快排

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