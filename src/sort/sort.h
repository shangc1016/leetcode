#ifndef __SORT_H_
#define __SORT_H_

#include <cstdlib>
#include <functional>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

namespace sort {

int findKthLargest(vector<int>& nums, int k);

int findKthLargest(vector<int>& nums, int k);

// 快排-升序排序
template <class T>
class QuickSort {
 private:
  static int partition(vector<T>& vec, int low, int high) {
    int i = low;
    int j = high + 1;
    T value = vec[low];
    while (true) {
      while (vec[++i] < value)
        if (i == high) break;
      while (value < vec[--j])
        if (j == low) break;
      if (i >= j) break;
      std::swap(vec[i], vec[j]);
    }
    std::swap(vec[low], vec[j]);
    return j;
  }

  static void quick_sort(vector<T>& vec, int low, int high) {
    if (low >= high) return;
    // 寻找枢轴，然后以枢轴为界，分治
    int pivot = partition(vec, low, high);
    quick_sort(vec, low, pivot - 1);
    quick_sort(vec, pivot + 1, high);
  }

 public:
  static void quickSort(vector<T>& vec) { quick_sort(vec, 0, vec.size() - 1); }
};



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

// 堆排序-大顶堆
template <class T>
class HeapSort {
 private:
  // vec_[0]不使用
  vector<T> vec_;
  int size_;

  void sink(int cur) {
    while (2 * cur <= size_) {
      int index = cur * 2;
      if (index < size_ && vec_[index + 1] > vec_[index]) {
        index++;
      }
      if (vec_[index] <= vec_[cur]) break;
      swap(vec_[index], vec_[cur]);
      cur = index;
    }
  }

  void swim(int cur) {
    while (cur > 1 && vec_[cur / 2] < vec_[cur]) {
      swap(vec_[cur / 2], vec_[cur]);
      cur = cur / 2;
    }
  }

  void InitHeap() {
    for (int cur = size_; cur > 1; cur--) {
      swim(cur);
    }
  }

 public:
  HeapSort(vector<T>& vec) {
    // 这个是把vec_[0]占位
    vec_.push_back(vec.front());
    vec_.insert(vec_.end(), vec.begin(), vec.end());
    // Traverse();
    size_ = vec.size();
    InitHeap();
  }

  HeapSort() { size_ = 0; }

  void Insert(T value) {
    vec_[++size_] = value;
    swim(size_);
  }

  T Top() {
    if (size_ > 0) {
      return vec_[1];
    } else {
      //   ???
      return vec_[0];
    }
  }

  void Pop() {
    if (size_ <= 1) {
      size_ = 0;
    } else {
      swap(vec_[1], vec_[size_]);
      vec_.pop_back();
      size_--;
      sink(1);
    }
  }

  bool Empty() { return size_ == 0; }

  void Traverse() {
    for (int i = 1; i <= size_; i++) {
      cout << vec_[i] << endl;
    }
  }
};

int findKthLargest(vector<int>& nums, int k) {
  HeapSort<int> heap;
  for (auto item : nums) heap.Insert(item);
  for (int i = 0; i < k - 1; i++) heap.Pop();
  return heap.Top();
}

}  // namespace sort

#endif