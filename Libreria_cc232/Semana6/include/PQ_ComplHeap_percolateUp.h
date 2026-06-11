#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

#include "PQ_ComplHeap_macro.h"

namespace ods {

template <class T, class Compare>
std::size_t complHeapPercolateUp(std::vector<T>& a, std::size_t i, Compare comp) {
  while (pqHasParent(i)) {
    const std::size_t p = pqParent(i);
    if (!comp(a[p], a[i])) {
      break;
    }
    std::swap(a[p], a[i]);
    i = p;
  }
  return i;
}

// MOD-A6-B2
template <class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp) {
  std::size_t swaps = 0;
  while (pqHasParent(i)) {
    const std::size_t p = pqParent(i);
    if (!comp(a[p], a[i])) {
      break;
    }
    std::swap(a[p], a[i]);
    i = p;
    swaps++;
  }
  return swaps;
}
}  // namespace ods
