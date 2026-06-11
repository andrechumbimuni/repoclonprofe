#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

#include "PQ_ComplHeap_macro.h"

namespace ods {

template <class T, class Compare>
std::size_t complHeapPercolateDown(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp) {
  // MOD-A6-B1
  while (pqInHeap(i, n) && !pqIsLeaf(i, n) ) {
    std::size_t c = pqLeftChild(i);
    if (pqHasRightChild(i, n) && comp(a[c], a[pqRightChild(i)])) {
      c = pqRightChild(i);
    }
    if (!comp(a[i], a[c])) {
      break;
    }
    std::swap(a[i], a[c]);
    i = c;
  }
  return i;
}

}  // namespace ods
