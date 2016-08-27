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

// min heap.

const int N = 100010;

int x[N], sz;

// go up if cur should go according to heap property.
inline void pushUp(int cur) {
  while (cur > 0) {
    int par = ((cur - 1) >> 1);
    if (x[par] > x[cur]) {
      swap(x[par], x[cur]);
      cur = par;
    } else break;
  }
}

// go down if cur should go according to heap property.
inline void pushDown(int cur) {
  while (true) {
    int minchild = cur + cur + 1;
    if (minchild >= sz) break;
    if (minchild + 1 < sz && x[minchild + 1] < x[minchild]) {
      minchild++;
    }
    if (x[minchild] < x[cur]) {
      swap(x[minchild], x[cur]);
      cur = minchild;
    } else break;
  }
}

// add new element same as push in priority queue.
inline void add(int a) {
  x[sz] = a;
  pushUp(sz++);
}

// get min element, here min heap.
inline int getMin() {
  if (sz > 0) {
    int ans = x[0];
    swap(x[0], x[sz - 1]);
    sz--;
    pushDown(0);
    return ans;
  }
  return -1;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int cmd, a;
    scanf("%d", &cmd);
    if (cmd == 0) {
      scanf("%d", &a);
      add(a);
    } else {
      printf("%d\n", getMin());
    }
  }
}
