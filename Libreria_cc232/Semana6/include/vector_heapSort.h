#pragma once

#include <algorithm>
#include <functional>
#include <vector>

#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_ComplHeap_percolateDown.h"

namespace ods {

template <class T, class Compare = std::less<T>>
void heapSort(std::vector<T>& a, Compare comp = Compare{}) {
  if (a.size() < 2) {
    return;
  }
  complHeapHeapifyFloyd(a, comp);
  for (std::size_t n = a.size(); n > 1; --n) {
    std::swap(a[0], a[n - 1]);
    complHeapPercolateDown(a, n - 1, 0, comp);
  }
}
// MOD-A6-B6: Versión extendida para controlar el sentido del ordenamiento in-situ
template <class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending) {
  if (a.size() < 2) {
    return;
  }
  if (ascending) {
    complHeapHeapifyFloyd(a, comp);
    for (std::size_t n = a.size(); n > 1; --n) {
      std::swap(a[0], a[n - 1]);
      complHeapPercolateDown(a, n - 1, 0, comp);
    }
  } else {
    auto min_comp = [&](const T& x, const T& y) { return comp(y, x); };
    complHeapHeapifyFloyd(a, min_comp);
    for (std::size_t n = a.size(); n > 1; --n) {
      std::swap(a[0], a[n - 1]);
      complHeapPercolateDown(a, n - 1, 0, min_comp);
    }
  }
}

template <class T, class Compare = std::less<T>>
std::vector<T> heapSorted(std::vector<T> a, Compare comp = Compare{}) {
  heapSort(a, comp);
  return a;
}

}  // namespace ods
