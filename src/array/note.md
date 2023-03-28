

### 数组中的第K个最大元素


- 快排解法
```cpp
class Solution_215 {
 private:
  int partition(vector<int>& nums, int low, int high) {
    int i = low;
    int j = high + 1;
    int value = nums[low];
    while (true) {
      while (nums[++i] > value)
        if (i == high) break;
      while (value > nums[--j])
        if (j == low) break;
      if (i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[low]);
    return j;
  }

  int helper(vector<int>& nums, int low, int high, int k) {
    if (low >= high) return nums[low];
    while (true) {
      int pivot = partition(nums, low, high);
      if (pivot == k)
        return nums[pivot];
      else if (pivot > k) {
        return helper(nums, low, pivot - 1, k);
      } else {
        return helper(nums, pivot + 1, high, k);
      }
    }
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) return 0;
    return helper(nums, 0, nums.size() - 1, k - 1);
  }
};
```


- 堆方法

```cpp
// todo
```