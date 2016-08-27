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
// merge sort very useful also can add comparator.

const int N = 10010;

int a[N], aa[N];

inline bool cmp(int a, int b) {
  return a > b;
}

inline void mergeIt(int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (cmp(a[i], a[j])) {
      aa[k++] = a[i++];
    }  else {
      aa[k++] = a[j++];
    }
  }
  while (i <= mid) {
    aa[k++] = a[i++];
  }
  while (j <= r) {
    aa[k++] = a[j++];
  }
  for (int ii = l; ii <= r; ii++) {
    a[ii] = aa[ii];
  }
}

inline void mergeSort(int l, int r) {
  if (l < r) {
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    mergeIt(l, mid, r);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  mergeSort(0, n - 1);
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}


