#include "sorting.h"


void insertionSort(std::vector<float> &v) {
  for (std::size_t i = 1; i < v.size(); i++) {
    float key = v[i];
    std::size_t j;
    for (j = i - 1; j >= 0 && v[j] > key; j--) {
      v[j + 1] = v[j];
    }
    v[j + 1] = key;
  }
}
