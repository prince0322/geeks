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
// this function find KTH element in the sorted array.
// which will be constructed by merging of two sorted array a[], b[].

const int N = 10001;

int n, m;
int a[N], b[N];

// O(log k).
inline int findKth(int *a, int n, int *b, int m, int k) {
  if (n > m) {
    return findKth(b, m, a, n, k);
  }
  if (n == 0) {
    return b[k - 1];
  }
  if (k == 1) {
    return min(a[0], b[0]);
  }
  int i = min(k / 2, n), j = k - i;
  if (a[i - 1] > b[j - 1]) {
    return findKth(a, i, b + j, m - j, k - j);
  } else {
    return findKth(a + i, n - i, b, j, k - i);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int j = 0; j < m; j++) {
    scanf("%d", b + j);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    int ans = findKth(a, n, b, m, k);
    printf("%d\n", ans);
  }
}

