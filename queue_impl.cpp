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
// queue implementation using array.
// can be used for BFS graph traversal.

const int N = 100010;

int que[N], b, e; // begin, end.

inline void pop() {
  if (b < e) {
    b++;
  }
}

inline int front() {
  if (b < e) {
    return que[b];
  }
  return -1;
}

inline void push(int val) {
  que[e++] = val;
}

inline bool isEmpty() {
  return (b >= e);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    push(x);
  }
  while (!isEmpty()) {
    printf("%d ", front());
    pop();
  }
  putchar('\n');
}

