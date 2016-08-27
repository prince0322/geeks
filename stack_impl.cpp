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
// stack implementation using array.
// one of the application : convert number in binary.

const int N = 100010;

int stk[N], sz;

inline void push(int val) {
  stk[sz] = val;
  sz++;
}

inline int top() {
  if (sz > 0) {
    return stk[sz - 1];
  }
  return -1;
}

inline void pop() {
  if (sz > 0) {
    sz--;
  }
}

inline bool isEmpty() {
  return (sz <= 0);
}

int main() {
  int x;
  scanf("%d", &x);
  while (x > 0) {
    push(x % 2);
    x /= 2;
  }
  while (!isEmpty()) {
    printf("%d", top());
    pop();
  }
  putchar('\n');
}
