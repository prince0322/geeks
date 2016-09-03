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
// same concept as in stack, one FRE pointer point to current free slot.
// front[i] store front of the i th queue.
// rear[i] stores rear of the i th queue.

const int N = 100010;

int n = 100, fre = 0;
int que[N], nxt[N];
int frnt[N], rear[N];

inline void push(int qn, int val) {
  int i = fre;
  fre = nxt[fre];
  if (frnt[qn] == -1) {
    frnt[qn] = i;
  } else {
    nxt[rear[qn]] = i;
  }
  nxt[i] = -1;
  rear[qn] = i;
  que[i] = val;
}

inline void pop(int qn) {
  if (frnt[qn] != -1) {
    int i = frnt[qn];
    frnt[qn] = nxt[i];
    nxt[i] = fre;
    fre = i;
  }
}

inline int getFront(int qn) {
  if (frnt[qn] == -1) {
    return -1;
  }
  return que[frnt[qn]];
}

inline void init(int k) {
  for (int i = 1; i <=  k; i++) {
    frnt[i] = -1;
  }
  for (int i = 0; i <= n; i++) {
    nxt[i] = i + 1;
  }
  nxt[n] = -1;
  fre = 0;
}

int main() {
  int k;
  scanf("%d", &k);
  init(k);
  int q;
  scanf("%d", &q);
  while (q--) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 0) {
      int qn, val;
      scanf("%d %d", &qn, &val);
      push(qn, val);
    } else if (cmd == 1) {
      int qn;
      scanf("%d", &qn);
      pop(qn);
    } else {
      int qn;
      scanf("%d", &qn);
      printf("%d\n", getFront(qn));
    }
  }
}

