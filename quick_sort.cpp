#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <list>
#include <set>
#include <map>

using namespace std;
// worst case - O(n ^ 2)
// average case - O(n log n).
// main thing does not take extra memory.

const int N = 10010;

int a[N];

// select pivot and do partition according to them.
inline int doPartition(int l, int r) {
  int i = l - 1, pvt = a[r];
  for (int j = l; j < r; j++) {
    if (a[j] <= pvt) {
      swap(a[++i], a[j]);
    }
  }
  swap(a[++i], a[r]);
  return i;
}

inline void quickSort(int l, int r) {
  if (l < r) {
    int q = doPartition(l, r);
    quickSort(l, q - 1);
    quickSort(q + 1, r);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  quickSort(0, n - 1);
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

