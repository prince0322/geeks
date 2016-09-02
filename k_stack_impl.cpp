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

// Here we are going to implement k - stack in a single array.
// done using two extra array NXT[] and top[].

const int N = 100010;

int fre = 0;
int stk[N], tp[N], nxt[N];

// initially all top will point to -1
// and all next will be use for FRE pointer.
inline void init(int k) {
  for (int i = 1; i <= k; i++) {
    tp[i] = -1;
  }
  for (int i = 0; i <= 100; i++) {
    nxt[i] = i + 1;
  }
  nxt[100] = -1;
  fre = 0;
}

// FRE pointer will point next free pointer.
// and top[sn] will contain current free.
// previous top will be linked by next[i].
inline void push(int sn, int val) {
  int i = fre;
  fre = nxt[fre];
  nxt[i] = tp[sn];
  tp[sn] = i;
  stk[i] = val;
}

inline void pop(int sn) {
  int i = tp[sn];
  int val = stk[i];
  tp[sn] = nxt[i];
  nxt[i] = fre;
  fre = i;
}

inline bool isEmpty(int sn) {
  return (tp[sn] == -1);
}

inline int top(int sn) {
  if (tp[sn] == -1) {
    return -1;
  }
  return stk[tp[sn]];
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
      int sn, val;
      scanf("%d %d", &sn, &val);
      push(sn, val);
    } else if (cmd == 1) {
      int sn;
      scanf("%d", &sn);
      pop(sn);
    } else {
      int sn;
      scanf("%d", &sn);
      printf("%d\n", top(sn));
    }
  }
}

