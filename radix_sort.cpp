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
// is used to sort the number by digit because we can use count sort
// on digit so complexity will be O(n).
// sorting start from least significant digit.

const int N = 100010;
const int D = 10;

int a[N], b[N], cnt[D];

// counting sort based on rank.
void countSort(int n, int bit) {
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++) {
    int dz = (a[i] / bit) % 10;
    cnt[dz]++;
  }
  for(int i = 1; i < D; i++) {
    cnt[i] += cnt[i - 1];
  }
  for(int i = n - 1; i >= 0; i--) {
    int dz = (a[i] / bit) % 10;
    b[cnt[dz] - 1] = a[i];
    cnt[dz]--;
  }
  memcpy(a, b, n * sizeof(int));
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int bit = 1;
  for(int i = 1; i < D; i++) {
    countSort(n, bit);
    bit *= 10;
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

